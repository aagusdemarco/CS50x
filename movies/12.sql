SELECT movies.title FROM movies JOIN stars ON movies.id = stars.movie_id WHERE person_id IN (SELECT id FROM people WHERE name = 'Bradley Cooper' OR name = 'Jennifer Lawrence');
