USE concurrency;

CREATE USER egci321 IDENTIFIED BY "root";

SELECT USER FROM mysql.user;

ALTER USER egci321 ACCOUNT LOCK;

ALTER USER egci321 ACCOUNT UNLOCK;

SELECT USER , HOST, account_locked FROM mysql.user;

SELECT * FROM mysql.user;

GRANT SELECT ON concurrency.Balance TO egci321;

SHOW GRANTS FOR egci321;

REVOKE ALL PRIVILEGES, GRANT OPTION FROM egci321;

ALTER DATABASE concurrency READ ONLY =1;
ALTER DATABASE concurrency READ ONLY = 0;

UPDATE concurrency.balance SET balance = 500 WHERE accountID = 1;

DROP USER egci321;
