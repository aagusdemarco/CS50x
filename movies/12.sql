SELECT title FROM movies, stars, people WHERE movies.id = stars.movie_id AND people.id = stars.person_id AND name = 'Bradley Cooper' OR name = 'Jennifer Lawrence';
