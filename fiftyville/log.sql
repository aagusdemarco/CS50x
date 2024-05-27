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

-- Check for flights out of Fiftyville the day after the theft
SELECT * FROM flights
WHERE day = 29 AND month = 7 AND year = 2023
ORDER BY hour, minute ASC LIMIT 1;

-- Join all queries into a mega-query that will throw out the name of the thief
SELECT name FROM people

-- License plate
WHERE people.license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25)

-- Bank account
AND people.id IN (
    SELECT person_id FROM bank_accounts
    JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
    WHERE atm_transactions.year = 2023 AND atm_transactions.month = 7 AND atm_transactions.day = 28
    AND transaction_type = 'withdraw'
    AND atm_transactions.atm_location = 'Leggett Street')

-- Phone call from thief to accomplice
AND people.phone_number IN (
    SELECT caller FROM phone_calls
    WHERE year = 2023 AND month = 7 AND day = 28
    AND duration < 60)

-- Passport Number
AND people.passport_number IN (
    SELECT passport_number FROM passengers
    WHERE flight_id IN (
        SELECT id FROM flights WHERE year = 2023 AND month = 7 AND day = 29
        ORDER BY hour, minute ASC LIMIT 1));

