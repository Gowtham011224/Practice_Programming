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
    m_stockleft NUMBER(5),
    FOREIGN KEY (sup_id) REFERENCES suppliers(s_id));
INSERT INTO suppliers VALUES(1,'ABC','9344002774','a@gmail.com');
INSERT INTO suppliers VALUES(2,'DEF','8344005793','b@gmail.com');
INSERT INTO suppliers VALUES(3,'FIH','5342027774','c@gmail.com');
INSERT INTO suppliers VALUES(4,'MNO','9843076433','d@gmail.com');

INSERT INTO medicines VALUES(101,'PainAway',1,25,120);
INSERT INTO medicines VALUES(102,'CoughRelief',2,10,122);
INSERT INTO medicines VALUES(103,'thorcare',1,12,25);
INSERT INTO medicines VALUES(104,'medicure',3,5,12);
INSERT INTO medicines VALUES(105,'Paramol',3,15,21);
INSERT INTO medicines VALUES(106,'kimmol',3,200,50);

SELECT s_name FROM suppliers WHERE s_id IN (SELECT sup_id FROM medicines);
SELECT s_name FROM suppliers WHERE s_id IN (SELECT sup_id FROM medicines);
SELECT s_name FROM suppliers WHERE s_id IN (SELECT sup_id FROM medicines WHERE m_stockleft<100);
SELECT s_name,s_pnum FROM suppliers WHERE s_id NOT IN (SELECT sup_id FROM medicines);
SELECT m_id,m_name,m_stockleft FROM medicines WHERE sup_id=(SELECT s_id FROM suppliers WHERE s_name='ABC');
SELECT s_name,(SELECT COUNT(*) FROM medicines WHERE sup_id=suppliers.s_id) AS medicine_count FROM suppliers;
UPDATE medicines SET m_mrp=m_mrp*1.4 WHERE sup_id=(SELECT s_id FROM suppliers WHERE s_mail='a@gmail.com');
SELECT * FROM medicines;

SELECT m_id,m_name,s_name FROM medicines INNER JOIN suppliers ON sup_id=s_id;
SELECT m_id,m_name,s_name FROM medicines INNER JOIN suppliers ON sup_id=s_id AND m_stockleft>50;
SELECT m_name,m_mrp,s_id FROM suppliers INNER JOIN medicines ON sup_id=s_id;

DROP TABLE medicines;
DROP TABLE suppliers;
