You can use the application with these options:
```
dotnet run -- <file-path> <frame-size> <start-byte> <end-byte> [--ecc]
```

- `<file-path>`: The path to the file you want to process.
- `<frame-size>`: The size of each frame in bytes.
- `<start-byte>`: The starting byte value for the frame in hexadecimal format (e.g., `0x7E`).
- `<end-byte>`: The ending byte value for the frame in hexadecimal format (e.g., `0x7E`).
- `[--ecc]`: An optional flag to enable error correction code (ECC) addition to the frames.

> [!NOTE]
> Frame size here **ONLY** implies the data size of the frame, and does not include the start and end bytes. The actual frame size will be `frame-size + 2` bytes. With ECC, the LRC byte adds one more byte, for a total of `frame-size + 3` bytes (start + data + LRC + end).

For example with the `test.txt` file:
```
dotnet run -- test.txt 5 0x7E 0x7E --ecc
```

---

### Error Correction Code (ECC)

The ECC is a **vertical redundancy check (VRC)** on each data byte plus a **longitudinal redundancy check (LRC)** over the whole frame.

- **VRC:** each data byte is treated as a 7-bit ASCII value. The seven data bits stay in the low seven bits of the byte and an even-parity bit is stored in the most significant (eighth) bit. Because 7-bit ASCII never sets that bit, the parity bit can be stored there without disturbing the character value.
- **LRC:** once every data byte carries its VRC bit, the frame's LRC byte is the XOR of all of those encoded bytes. Since each byte already includes its own parity bit, the most significant bit of the LRC is the parity bit for the LRC itself.

### When the data uses all 8 bits

The scheme above only works because 7-bit ASCII leaves the most significant bit free. If a frame carries full 8-bit data (binary files, extended ASCII, UTF-8, image bytes, …), every bit of the byte is meaningful, so there is no spare bit left to hold the VRC.

If we insist on keeping the VRC in the most significant bit, the `& 0x7F` mask in `AddVrc` would silently truncate the top bit and corrupt the data. The parity bit has to go *somewhere*, and it cannot stay inside the same 8 bits.

**Suggested solution — the 9-bit VRC model:** widen the unit of transmission from 8 bits to 9 bits. Each 9-bit character carries the full 8 data bits plus one even-parity bit in the 9th position, so the data byte is never touched because the data and the parity now occupy separate bits.

Consequences to be aware of:

- A frame is no longer a multiple of 8 bits, so `<frame-size>` no longer maps cleanly to whole bytes. Either transmit 9-bit words over the channel, or pack them as a transport detail (for example two 9-bit words into 18 bits = 3 bytes).
- The LRC has to be computed at the same 9-bit width: XOR the 9-bit words and let the 9th bit be the LRC's own parity, mirroring the existing 8-bit behavior.
- The frame grows by 1 bit per character (12.5% overhead) plus the LRC.

**Alternative:** keep the data at a full 8 bits, drop the per-byte VRC, and rely on a frame-level check only — the existing LRC, or a stronger code such as CRC-8/CRC-16. This preserves the data exactly, at the cost of detecting fewer error patterns than a per-byte parity bit.

