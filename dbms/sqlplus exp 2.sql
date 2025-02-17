SET LINESIZE 100;
SET AUTOCOMMIT ON;
CREATE TABLE suppliers (
    s_id NUMBER(30) PRIMARY KEY,
    s_name VARCHAR2(100) NOT NULL,
    s_pnum VARCHAR2(15) NOT NULL,
    s_mail VARCHAR2(100) UNIQUE,
    CHECK (s_id>0) );

ALTER TABLE suppliers
ADD CONSTRAINT unique_phone_email_pair
UNIQUE (s_pnum, s_mail);

DESC suppliers;
INSERT INTO suppliers(s_name,s_pnum) VALUES('Elect','1123478900');
INSERT INTO suppliers(s_id,s_name,s_pnum) VALUES(5,'Elective','1123400900');
INSERT INTO suppliers VALUES(1,'Electron','1123400900','abc@example.com');    
INSERT INTO suppliers VALUES(2,'ABC Electronics','1234567890','abc@example.com');
INSERT INTO suppliers VALUES(3,'XYZ Components','1123400900','abc@example.com');
INSERT INTO suppliers VALUES(4,'Tech Innovators','5551112222','tech@example.com');
SELECT * FROM suppliers;
UPDATE suppliers SET s_mail='x@mail.com' WHERE s_id = 1;
SELECT * FROM suppliers;
DELETE FROM suppliers WHERE s_id=4;
SELECT * FROM suppliers;
UPDATE suppliers SET s_mail='y@mail.com' WHERE s_id = 5 AND s_name='Elective';
SELECT * FROM suppliers;
DROP TABLE suppliers;
