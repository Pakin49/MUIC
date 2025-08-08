-- Create database quiz2;
-- Use quiz2;

-- Create table Honda (
-- 	CarNo int not null primary key,
--     CarBrand varchar(20),
--     CarBodyType varchar(20),
--     CarModel varchar(20),
--     EngineType  varchar(20),
--     TransferredStatus int
-- );
-- Insert Honda values (5, 'Honda', 'Sedan','City', 'Petrol', 0);
-- Insert Honda values (9, 'Honda', 'Sedan','Accord', 'Petrol', 0);


-- 2.1 : Lost Updatae

-- 2.2 : Read Comitted can solve this problem
SET SQL_SAFE_UPDATES = 0;
-- 2.3 
SET SESSION TRANSACTION ISOLATION LEVEL READ COMMITTED;
START TRANSACTION;
UPDATE Honda SET TransferredStatus = 1
WHERE TransferredStatus = 0;

SELECT SLEEP(10);
COMMIT;

SELECT * FROM HONDA;