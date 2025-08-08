use lecture05;
CREATE TABLE Movie(
	movieid varchar(20) NOT NULL,
    title varchar(20) NULL,
    year int NULL,
    length int NULL,
    genre varchar(20) NULL,
    PRIMARY KEY ( movieid ASC)
);

INSERT Movie(title,year,length,genre,movieid) VALUE ('Chocolate Factory', 2006, 112, 'Drama', 'M001');
INSERT Movie(title,year,length,genre,movieid) VALUE ('Star Wars', 1997, 124, 'Sci-fi', 'M002');
INSERT Movie(title,year,length,genre,movieid) VALUE  ('Wizard of Oz', 1970, 200, 'Advanture', 'M003');

CREATE TABLE moviestar(
	starid varchar(20) NOT NULL,
    name varchar(20) ,
    address varchar(20),
    gender nchar(2),
    movieid varchar(20) NOT NULL,
    PRIMARY KEY (starid ASC)
);
ALTER TABLE moviestar
ADD FOREIGN KEY (movieid) REFERENCES Movie(movieid);

INSERT moviestar VALUE ('S01', 'Wookiee', 'Hollywood North st.', 'm', 'M002');
INSERT moviestar VALUE ('S02', 'Willy Wongka', 'Hollywood East st.', 'm', 'M001');
INSERT moviestar VALUE ('S03', 'Dorothy', 'Hollywood West ave.', 'f', 'M003');
