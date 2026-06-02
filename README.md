# University Projects

This repository contains personal coding exercises and practice problems organized by subject area.

## Structure

- **Computer Architecture**: Assembly language programs and exercises
- **Object Oriented Programming**: Java applications and practical sessions
- **Operating System Architecture**: Practical exercises related to OS concepts

## Usage

Each folder contains its own exercises and implementations. Refer to individual source files for specific implementations.

### Running MSSQL server

```sh
# Start the MSSQL server using Docker
docker compose -f .devcontainer/mssql-docker-compose.yml up -d mssql

# To stop the MSSQL server
docker compose -f .devcontainer/mssql-docker-compose.yml down -d mssql
```

> [!NOTE]
> The server is exposed on port 1433, you can use the MSSQL extension for Visual Studio Code to connect to it using the following credentials:
> - **Server**: localhost,1433
> - **Username**: sa
> - **Password**: LocalDevStrong!Passw0rd

## Disclaimer

This repository contains my personal solutions to various programming exercises.

- **Ownership**: All source code is written by me.
- **Copyright**: No university-provided documents or problem statements are included to ensure compliance with copyright policies.
- **Usage**: Not intended for plagiarism; use for educational reference only.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
