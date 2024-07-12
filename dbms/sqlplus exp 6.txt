CREATE TABLE suppliers (
    s_id NUMBER(5) PRIMARY KEY,
    s_name VARCHAR2(100) NOT NULL,
    s_pnum VARCHAR2(15),
    s_mail VARCHAR2(100) UNIQUE);
CREATE TABLE medicines (
    m_id NUMBER(5) PRIMARY KEY,
    m_name VARCHAR2(100) NOT NULL,
    sup_id NUMBER(5),
    m_mrp NUMBER(5),
    m_stockleft NUMBER(5));
INSERT INTO suppliers VALUES(1,'ABC','9344002774','a@gmail.com');
INSERT INTO suppliers VALUES(2,'DEF','8344005793','b@gmail.com');
INSERT INTO suppliers VALUES(3,'FIH','5342027774','c@gmail.com');
INSERT INTO suppliers VALUES(4,'MNO','9843076433','d@gmail.com');
INSERT INTO suppliers VALUES(5,'MOO','9876307643','e@gmail.com');
INSERT INTO medicines VALUES(101,'PainAway',1,25,120);
INSERT INTO medicines VALUES(102,'CoughRelief',2,10,122);
INSERT INTO medicines VALUES(103,'thorcare',1,12,25);
INSERT INTO medicines VALUES(104,'medicure',3,5,12);
INSERT INTO medicines VALUES(105,'Paramol',3,15,21);
INSERT INTO medicines VALUES(106,'kimmol',8,200,50);
SELECT * FROM suppliers;
SELECT * FROM medicines;

ALTER TABLE medicines RENAME COLUMN sup_id TO s_id;
SELECT * FROM suppliers NATURAL JOIN medicines;
ALTER TABLE medicines RENAME COLUMN s_id TO sup_id;

SELECT * FROM suppliers JOIN medicines ON s_id=sup_id;

SELECT s_id,s_name,m_ID,m_name FROM suppliers LEFT JOIN medicines ON s_id=sup_id;

SELECT s_id,s_name,m_ID,m_name FROM suppliers RIGHT JOIN medicines ON s_id=sup_id;

SELECT s_id,s_name,m_ID,m_name FROM suppliers FULL OUTER JOIN medicines ON s_id=sup_id;

SELECT s_id,m_id FROM suppliers cross join medicines where s_id<3;

CREATE TABLE r1 AS (SELECT s_id,s_name FROM suppliers);
CREATE TABLE r2 AS (SELECT s_id,s_pnum,s_mail FROM suppliers);
CREATE TABLE r3 AS (SELECT s_id,s_pnum FROM suppliers WHERE s_id<3);

SELECT * FROM r1 NATURAL JOIN r2;
SELECT * FROM r1 NATURAL JOIN r3;

DROP TABLE r1;
DROP TABLE r2;
DROP TABLE r3;
DROP TABLE suppliers;
DROP TABLE medicines;

