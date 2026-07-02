-- KHOAHOC
INSERT INTO KHOAHOC (MAKH, TENKH, NGAYBD, NGAYKT) VALUES
('K001', 'Khóa 1', '2020-01-10', '2020-03-20'),
('K002', 'Khóa 2', '2020-02-28', '2020-05-28'),
('K003', 'Khóa 3', '2020-04-10', '2020-07-20'),
('K004', 'Khóa 4', '2020-06-15', '2020-07-20');

-- CHUONGTRINH
INSERT INTO CHUONGTRINH (MACT, TENCT) VALUES
('CT007', 'Chung chi tieng anh 6 bac(A1,B1,B2,C1)'),
('CT006', 'Chuong trinh Cambridge'),
('CT005', 'Tieng anh IELTS'),
('CT004', 'Chuong trinh Toeic'),
('CT003', 'Tieng anh luyen ky nang'),
('CT002', 'tieng anh tre em'),
('CT001', 'tieng anh tong quat');

-- LOAILOP
INSERT INTO LOAILOP (MALOAI, MACT, TENLOAI) VALUES
('LL001', 'CT001', N'Tiếng Anh căn bản'),
('LL002', 'CT001', N'Tiếng Anh A1'),
('LL003', 'CT001', N'Tiếng Anh A2'),
('LL004', 'CT001', N'Tiếng Anh B1'),
('LL005', 'CT001', N'Tiếng Anh B2'),
('LL006', 'CT001', N'Tiếng Anh C1');

-- LOP
INSERT INTO LOP (MALOP, MALOAI, TENLOP, SISO, MAKH) VALUES
('L001', 'LL001', N'Lớp 1', 30, 'K001'),
('L002', 'LL001', N'Lớp 2', 30, 'K001'),
('L003', 'LL002', N'Lớp 1', 25, 'K001');

-- HOCVIEN
INSERT INTO HOCVIEN (MAHV, TENHV, GIOITINH, NGAYSINH, SDT, DIACHI) VALUES
('HV0001', N'Đỗ Bình An', '1', '2000-11-02', '917217036', N'Cờ Đỏ - Cần Thơ'),
('HV0002', N'Đỗ Gia Bảo', '1', '2001-12-02', '917217036', N'Ô Môn - Cần Thơ'),
('HV0003', N'Đỗ Phúc Vinh', '1', '2002-11-02', '917217036', N'Cù Lao Dung'),
('HV0004', N'Thạch Chí Tâm', '1', '2000-01-02', '917217036', N'Châu Thành'),
('HV0005', N'Lê Cẩm Giao', '0', '2000-11-05', '917217036', N'Phong Điền'),
('HV0006', N'Huỳnh Gia Bảo', '1', '2000-11-02', '917217036', N'Phong Điền'),
('HV0007', N'Học Viên Dự Phòng', '1', '2000-01-01', '917217036', N'Cần Thơ');

-- PHIEUTHU
INSERT INTO PHIEUTHU (SOPT, MAHV, MALOP, NGAYLAPPHIEU, THANHTIEN) VALUES
('PT000002', 'HV0002', 'L001', '2021-06-01', 1350000),
('PT000003', 'HV0003', 'L001', '2021-06-02', 1350000),
('PT000004', 'HV0004', 'L001', '2021-06-03', 1350000),
('PT000005', 'HV0005', 'L001', '2021-06-04', 1350000),
('PT000006', 'HV0006', 'L001', '2021-06-05', 1350000),
('PT000007', 'HV0007', 'L001', '2021-06-06', 1350000);