SELECT AVG(songs.energy)
FROM songs
JOIN artists ON artists.id = songs.artist_id
GROUP BY artists.name
HAVING artists.name = 'Drake';
