-- Keep a log of any SQL queries you execute as you solve the mystery.

-- see what interviews from day of theft contain.
SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;

-- get names of people whose plate was at the bakery within ten minutes of crime
SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 And minute <= 25);

-- get time of earliest flight the following day
SELECT * FROM flights  WHERE year = 2021 AND month = 7 AND day = 29;

-- get names of people who used cash machine on leggett st that day
SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street'));

-- get names of people who made a call less than 60 seconds duration on that day
SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration <= 60);

-- get names of people on earliest flight the following day
SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 AND hour = 8));

-- get names of people from above four conditions in one query
SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street')) AND phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration <= 60) AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 AND hour = 8)) AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 And minute <= 25);

-- get name relating to number that received Bruce's call on the day and duration
SELECT name FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE caller IN (SELECT phone_number FROM people WHERE name = 'Bruce') AND duration <= 60 AND year = 2021 AND month = 7 AND day = 28);



