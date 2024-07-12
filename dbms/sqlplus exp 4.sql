CREATE TABLE pharmacy(branch_id VARCHAR2(10),branch_name VARCHAR2(20),branch_phoneno NUMBER(10),branch_mail VARCHAR2(30),branch_location VARCHAR2(50));

desc pharmacy;
 
ALTER TABLE pharmacy ADD extracolumn varchar2(10);

desc pharmacy;

ALTER Table pharmacy DROP COLUMN extracolumn;
desc pharmacy;

ALTER Table pharmacy MODIFY branch_id NUMBER(5);
desc pharmacy;

INSERT into pharmacy VALUES(1000,'Adayarpharm',314567,'adayar.pharm@gmail.com','xxx street,PASS road,chennai-600987');
INSERT into pharmacy VALUES(1900,'Arakonampharm',376567,'arakonam.pharm@gmail.com','xxx street,madurai');
INSERT into pharmacy VALUES(1070,'Avadipharm',314357,'avadi.pharm@gmail.com','tiruchi');
INSERT into pharmacy VALUES(1670,'Pallavarampharm',123457,'pallavaram.pharm@gmail.com','xxx street,kodai');
INSERT into pharmacy VALUES(1230,'Tirupharm',310007,'tiru.pharm@gmail.com','xxx street');
INSERT into pharmacy VALUES(3450,'Chrompetpharm',309767,'chrompet.pharm@gmail.com','xxx street,PASS road,chennai-600987');
INSERT into pharmacy VALUES(7540,'OMRpharm',354767,'omr.pharm@gmail.com','xxx street,PASS road,chennai-600987');
INSERT into pharmacy VALUES(1450,'Mangulampharm',300067,'mang.pharm@gmail.com','xxx street,PASS road,chennai-600987');
INSERT into pharmacy VALUES(1090,'Hillpharm',318760,'hill.pharm@gmail.com','xxx street,PASS road,chennai-600987');
INSERT into pharmacy VALUES(1620,'Fallspharm',317767,'falls.pharm@gmail.com','xxx street,PASS road,chennai-600987');

SELECT * FROM pharmacy;
SELECT branch_id FROM pharmacy WHERE branch_id>1500 OR branch_phoneno=314567;
SELECT branch_mail FROM pharmacy WHERE branch_name='Avadipharm' AND branch_phoneno=314357;

UPDATE pharmacy SET branch_id=1888 WHERE branch_phoneno=123457;

SELECT * FROM pharmacy ORDER BY branch_id;

SELECT sum(branch_id) FROM pharmacy GROUP BY branch_id having branch_id<3450;

SELECT avg(branch_phoneno) FROM pharmacy WHERE branch_id>1540 GROUP BY branch_id;

CREATE table dup_pharmacy AS SELECT * FROM pharmacy;
 
TRUNCATE table dup_pharmacy;
SELECT * from dup_pharmacy;
desc dup_pharmacy;
DROP table dup_pharmacy;

