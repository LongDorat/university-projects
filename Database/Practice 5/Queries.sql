----------------------------------------------------
CREATE TABLE khuvuc
(
    IP varchar(20) NOT NULL PRIMARY KEY,
    tenKhuvuc varchar(30) not null,
    tang smallint
);
----------------------------------------------------
CREATE TABLE phong
(
    MP varchar(20) NOT NULL PRIMARY KEy,
    tenphong varchar(20) not null,
    somay smallint,
    IP varchar(20),
    foreign key(IP) references khuvuc(IP)
);
----------------------------------------------------
create table loai
(
    idloai varchar(20) not null primary key,
    tenloai varchar(30) not null
);
----------------------------------------------------
create table may
(
    idMay varchar(20) not null primary key,
    tenmay varchar(20) not null,
    IP varchar(20),
    ad smallint check (ad BETWEEN 0 and 255),
    idloai varchar(20),
    MP varchar(20),
    foreign key(IP) references khuvuc(IP),
    foreign key(idloai) references loai(idloai)
);
----------------------------------------------------
create table phanmem
(
    idPM varchar(20) not null primary key,
    tenPM varchar(30) not null,
    ngaymua date,
    version varchar(20),
    idloai varchar(20),
    gia smallint check(gia>=0),
    foreign key(idloai) references loai(idloai)
);
----------------------------------------------------
create table caidat
(
    id varchar(20) not null primary key,
    idMay varchar(20),
    idPM varchar(20),
    ngaycai date default CURRENT_TIMESTAMP,
    foreign key(idMay) references may(idMay),
    foreign key(idPM) references phanmem(idPM)
);

-- INTELISENSES PURPOSES --

-- 1
SELECT _may.idMay, _loai.tenloai
FROM may _may, loai _loai
WHERE _may.idloai = _loai.idloai AND _may.idMay = 'p8';

-- 2
SELECT _phanMem.tenPM, _phanMem.idloai
FROM phanmem _phanMem
WHERE _phanMem.idloai = 'UNIX';

-- 3
SELECT _phong.tenphong, _phong.IP, _phong.MP
FROM phong _phong
    JOIN May _may ON _phong.MP = _may.MP
WHERE _may.idloai IN ('UNIX', 'PCWS');

-- 4
SELECT _phong.tenphong, _phong.IP, _phong.MP
FROM phong _phong
    JOIN May _may ON _phong.MP = _may.MP
WHERE _may.idloai IN ('UNIX', 'PCWS') AND _phong.IP = '130.120.80'
ORDER BY _phong.MP;

-- 5
SELECT idMay, COUNT(idPM) AS SoLuongPM
FROM caidat
WHERE idMay = 'p6'
GROUP BY idMay;

-- 6
SELECT idPM, COUNT(idMay) AS SoLuongMay
FROM caidat
WHERE idPM = 'log1'
GROUP BY idPM;

-- 7
SELECT _may.tenmay, CONCAT(_may.IP, '.', _may.ad) AS DiaChiMay
FROM may _may
WHERE _may.idloai = 'TX';

-- 8
SELECT idMay, COUNT(idPM) AS SoLuongPM
FROM caidat
GROUP BY idMay;

-- 9
SELECT idPM, COUNT(idMay) AS SoLuongMay
FROM caidat
GROUP BY idPM;

-- 10
SELECT _phanmem.idloai, AVG(_phanmem.gia) AS GiaTB
FROM phanmem _phanmem
WHERE _phanmem.idloai = 'UNIX'
GROUP BY _phanmem.idloai;

-- 11
SELECT ngaymua
FROM phanmem
WHERE ngaymua = (
    SELECT MAX(ngaymua)
    FROM phanmem
);

-- 12
SELECT idMay, COUNT(idPM) AS SoLuongPM
FROM caidat
GROUP BY idMay
HAVING COUNT(idPM) > 1;

-- 13
SELECT _loai.idloai, _loai.tenloai
FROM loai _loai
    LEFT JOIN may _may ON _loai.idloai = _may.idloai
WHERE _may.idloai IS NULL;

-- 14
SELECT _loai.idloai, _loai.tenloai
FROM loai _loai
WHERE EXISTS (
    SELECT 1
    FROM phanmem _phanmem
    WHERE _phanmem.idloai = _loai.idloai
)
    AND EXISTS (
    SELECT 1
    FROM may _may
    WHERE _may.idloai = _loai.idloai
);

-- 15
SELECT DISTINCT _may.idloai
FROM may _may
WHERE NOT EXISTS (
    SELECT 1
    FROM phanmem _phanmem
    WHERE _phanmem.idloai = _may.idloai
);

-- 16
SELECT _may.idMay, _may.tenmay, CONCAT(_may.IP, '.', _may.ad) AS DiaChiMay
FROM may _may
WHERE EXISTS (
    SELECT 1
    FROM caidat _caidat
    WHERE _caidat.idMay = _may.idMay AND _caidat.idPM = 'log6'
);

-- 17
SELECT _may.idMay, _may.tenmay, CONCAT(_may.IP, '.', _may.ad) AS DiaChiMay
FROM may _may
    JOIN caidat _caidat ON _may.idMay = _caidat.idMay
    JOIN phanmem _phanmem ON _caidat.idPM = _phanmem.idPM
WHERE _phanmem.tenPM = 'Oracle 8';

-- 18
SELECT _khuvuc.tenKhuvuc
FROM khuvuc _khuvuc
    JOIN phong _phong ON _khuvuc.IP = _phong.IP
    JOIN may _may ON _phong.MP = _may.MP
WHERE _may.idloai = 'TX'
GROUP BY _khuvuc.tenKhuvuc
HAVING COUNT(_may.idMay) = 3;

-- 19
SELECT _phong.tenphong
FROM phong _phong
    JOIN may _may ON _phong.MP = _may.MP
    JOIN caidat _caidat ON _may.idMay = _caidat.idMay
    JOIN phanmem _phanmem ON _caidat.idPM = _phanmem.idPM
WHERE _phanmem.tenPM = 'Oracle 6'
GROUP BY _phong.tenphong
HAVING COUNT(_phanmem.idPM) > 1;

-- 20
SELECT _phanmem.tenPM
FROM phanmem _phanmem
WHERE ngaymua = (
    SELECT MAX(ngaymua)
    FROM phanmem
);

-- 21
SELECT _phanmem.*
FROM phanmem _phanmem
WHERE _phanmem.idloai = 'PCNT'
    AND _phanmem.gia > ANY (
        SELECT _phanmem2.gia
        FROM phanmem _phanmem2
        WHERE _phanmem2.idloai = 'UNIX'
    );

-- 22
SELECT _phanmem.*
FROM phanmem _phanmem
WHERE _phanmem.idloai = 'UNIX'
    AND _phanmem.gia > ALL (
        SELECT _phanmem2.gia
        FROM phanmem _phanmem2
        WHERE _phanmem2.idloai = 'PCNT'
    );

-- 23
SELECT DISTINCT _may.*
FROM may _may
    JOIN caidat _caidat ON _may.idMay = _caidat.idMay
WHERE _caidat.idPM IN (
    SELECT idPM
    FROM caidat
    WHERE idMay = 'p6'
)
    AND _may.idMay <> 'p6';

-- 24
SELECT _may.idMay, _may.tenmay
FROM may _may
    JOIN caidat _caidat ON _may.idMay = _caidat.idMay
WHERE _may.idMay <> 'p6'
    AND _caidat.idPM IN (
        SELECT idPM
        FROM caidat
        WHERE idMay = 'p6'
    )
GROUP BY _may.idMay, _may.tenmay
HAVING COUNT(DISTINCT _caidat.idPM) = (
    SELECT COUNT(DISTINCT idPM)
    FROM caidat
    WHERE idMay = 'p6'
);