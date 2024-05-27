-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Check the crime_scene_reports table for info on crimes comitted on Humphrey Street, July 28, 2023.
SELECT * FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year = 2023 AND street = 'Humphrey Street';

-- Check the witnesses' interviews for more info, knowing that all of them mentioned the bakery
SELECT * FROM interviews
WHERE transcript LIKE '%bakery%'
AND day = 28 AND month = 7 AND year = 2023;

-- Based on the interviews, we can investigate each of the events mentioned by them
-- First, check for cars leaving the bakery parking lot
SELECT * FROM bakery_security_logs
WHERE day = 28 AND month = 7 AND year = 2023
AND hour = 10 AND minute BETWEEN 15 AND 25;

-- Then, check for ATM withdrawals that ocurred the day of the theft
SELECT * FROM atm_transactions
WHERE day = 28 AND month = 7 AND year = 2023
AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

-- Lastly, check for the two clues mentioned by the last witness
-- Check for calls which duration is less than a minute
SELECT * FROM phone_calls
WHERE day = 28 AND month = 7 AND year = 2023
AND duration < 60;

-- Check for 
