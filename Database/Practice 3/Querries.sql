CREATE TABLE TACPHAM
(
    NT smallint primary key ,
    tua varchar(150),
    tacgia varchar(100)
)
;

CREATE TABLE DOCGIA
(
    ND smallint PRIMARY KEY ,
    ho VARCHAR(30),
    ten VARCHAR(30),
    dchi VARCHAR(100),
    tel CHAR(10)
)
;

CREATE TABLE SACH
(
    NS smallint primary key ,
    nxb varchar(50),
    NT smallint not null,
    foreign key(NT) references TACPHAM(NT)
);

CREATE TABLE MUON
(
    NS smallint not NULL,
    foreign key(NS) references SACH(NS),
    ngaymuon date not NULL,
    hantra date not null,
    ngaytra date,
    ND smallint not null,
    foreign key(ND) references DOCGIA(ND),
    primary key 	(NS, ngaymuon)
)
;

-- 1
SELECT *
FROM TACPHAM;
SELECT *
FROM DOCGIA;
SELECT *
FROM SACH;
SELECT *
FROM MUON;

-- 3
SELECT NT, tua
FROM TACPHAM
WHERE (tacgia = 'Guy de Maupassant');

-- 4
SELECT *
FROM DOCGIA
WHERE (dchi = '32 rue des Alouettes, 75003 Paris');

-- 5
SELECT DISTINCT _sach.nxb
FROM SACH _sach
    INNER JOIN TACPHAM _tacPham ON _sach.NT = _tacPham.NT
WHERE _tacPham.tua LIKE '%Fleur%';

-- 6
SELECT tua
FROM TACPHAM
WHERE tua LIKE 'Le%';

-- 7
SELECT _docGia.ten
FROM DOCGIA _docGia
    INNER JOIN MUON _muon ON _docGia.ND = _muon.ND
WHERE _muon.ngaymuon BETWEEN '2007-09-15' AND '2007-09-20';

-- 8
SELECT DISTINCT _sach.nxb
FROM SACH _sach
    INNER JOIN TACPHAM _tacPham ON _sach.NT = _tacPham.NT
WHERE _tacPham.tua LIKE '%Germinal%';

-- 9
SELECT _docGia.ten
FROM DOCGIA _docGia
WHERE EXISTS (
    SELECT 1
FROM MUON _muon
    INNER JOIN SACH _sach ON _muon.NS = _sach.NS
    INNER JOIN TACPHAM _tacPham ON _sach.NT = _tacPham.NT
WHERE _muon.ND = _docGia.ND
    AND _tacPham.tua LIKE '%Po�e%'
);

-- 10
SELECT _docGia.*
FROM DOCGIA _docGia
WHERE EXISTS (
    SELECT 1
FROM MUON _muon
    INNER JOIN SACH _sach ON _muon.NS = _sach.NS
    INNER JOIN TACPHAM _tacPham ON _sach.NT = _tacPham.NT
WHERE _muon.ND = _docGia.ND
    AND _tacPham.tua LIKE 'Les Fleurs du mal'
);

-- 11
SELECT _tacPham.tua, _docGia.ten
FROM MUON _muon
    INNER JOIN DOCGIA _docGia ON _muon.ND = _docGia.ND
    INNER JOIN SACH _sach ON _muon.NS = _sach.NS
    INNER JOIN TACPHAM _tacPham ON _sach.NT = _tacPham.NT
WHERE _muon.ngaytra > _muon.hantra;

-- 12
SELECT _tacPham.tua, _docGia.ten
FROM MUON _muon
    INNER JOIN DOCGIA _docGia ON _muon.ND = _docGia.ND
    INNER JOIN SACH _sach ON _muon.NS = _sach.NS
    INNER JOIN TACPHAM _tacPham ON _sach.NT = _tacPham.NT
WHERE _muon.ngaytra < _muon.hantra;

-- 13
SELECT _docGia.ten
FROM DOCGIA _docGia
WHERE EXISTS (
    SELECT 1
FROM MUON _muon
    INNER JOIN SACH _sach ON _muon.NS = _sach.NS
    INNER JOIN TACPHAM _tacPham ON _sach.NT = _tacPham.NT
WHERE _docGia.ND = _muon.ND
    AND _tacPham.tacgia = 'Victor Hugo'
);

-- 14
SELECT _docGia.ten, _tacPham.tua
FROM MUON _muon
    INNER JOIN DOCGIA _docGia ON _muon.ND = _docGia.ND
    INNER JOIN SACH _sach ON _muon.NS = _sach.NS
    INNER JOIN TACPHAM _tacPham ON _sach.NT = _tacPham.NT
WHERE YEAR(_muon.ngaymuon) = 2007

-- 15
SELECT COUNT(DISTINCT NT) AS [Số tác phẩm]
FROM SACH