-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Check the crime_scene_reports table for info on crimes comitted on Humphrey Street, July 28, 2023.

SELECT * FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year = 2023 AND street = 'Humphrey Street';
