
CREATE TABLE Balance_log (
   action VARCHAR(50),
   action_time   TIMESTAMP,
   AccountID INT NOT NULL ,
   Name VARCHAR(50) NOT NULL,
   Balance  Int NOT NULL 
);

use concurrency;
-- Set INSERT Trigger
DELIMITER $$
CREATE TRIGGER balance_insert_trigger AFTER INSERT ON Balance
FOR EACH ROW
BEGIN
  INSERT INTO Balance_log (action, action_time, AccountID, Name, Balance)
  VALUES('insert', NOW(), NEW.AccountID, NEW.Name, NEW.Balance);
END$$
DELIMITER ;

INSERT Balance VALUES (1, 'Bob', 1000);
INSERT Balance VALUES (2, 'Mary', 800);
INSERT Balance VALUES (3, 'Sam', 800);
INSERT Balance VALUES (4, 'Jame', 1200);
INSERT Balance VALUES (5, 'June', 1400);

-- Set DELETE Trigger
DELIMITER $$
CREATE TRIGGER balance_delete_trigger AFTER DELETE ON Balance
FOR EACH ROW
BEGIN
  INSERT INTO Balance_log (action, action_time, AccountID, Name, Balance)
  VALUES('delete', NOW(), OLD.AccountID, OLD.Name, OLD.Balance);
END$$
DELIMITER ;


-- Set UPDATE Trigger
DELIMITER $$
CREATE TRIGGER balance_update_trigger AFTER UPDATE ON Balance
FOR EACH ROW
BEGIN
  INSERT INTO Balance_log (action, action_time, AccountID, Name, Balance)
  VALUES('update', NOW(), NEW.AccountID, NEW.Name, NEW.Balance);
END$$
DELIMITER ;

UPDATE BALANCE SET BALANCE = 900 WHERE accountID = 2;

-- Delete Trigger
DROP TRIGGER balance_insert_trigger;
DROP TRIGGER balance_delete_trigger;
DROP TRIGGER balance_update_trigger;
