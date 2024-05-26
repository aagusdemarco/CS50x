SELECT name FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON stars.movie_id = movies.id
WHERE movies.id IN (SELECT movie_id FROM movies)
