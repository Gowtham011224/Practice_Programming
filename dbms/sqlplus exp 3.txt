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

INSERT INTO suppliers VALUES(1,'ABC Sharma','9638527410','john@abcpharma.com');
INSERT INTO suppliers VALUES(2,'XYZ Healthcare','7895463210','jane@xyzhealthcare.com');

INSERT INTO medicines VALUES(101,'PainAway',1,25,120);
INSERT INTO medicines VALUES(102,'CoughRelief',2,10,122); 

SELECT * FROM suppliers;
SELECT * FROM medicines;

INSERT INTO medicines VALUES(103,'FeverFix',3,12,230);

INSERT INTO suppliers VALUES(3,'thorcare','7897453210','e@thorcare.com');

SELECT s_id FROM suppliers UNION SELECT sup_id FROM medicines;
SELECT s_id FROM suppliers UNION ALL SELECT sup_id FROM medicines;
SELECT s_id FROM suppliers INTERSECT SELECT sup_id FROM medicines;
SELECT s_id FROM suppliers MINUS SELECT sup_id FROM medicines;
SELECT sup_id FROM medicines MINUS SELECT s_id FROM suppliers;

INSERT INTO medicines VALUES(103,'FeverFix',3,12,230);
INSERT INTO medicines VALUES(104,'FFreix',4,10,30);
ALTER TABLE medicines RENAME COLUMN m_mrp TO m_amt;
DESC medicines;

DROP TABLE suppliers;
DROP TABLE medicines;
DROP TABLE suppliers;


