const mysql = require('mysql2');
require('dotenv').config({path : `../../.env`});

console.log(process.env.DB_HOST);

const db = mysql.createConnection({ // connection pool 로 고치기
    host: process.env.DB_HOST,
    user: process.env.DB_USER,
    port: process.env.DB_PORT,
    database: process.env.DB_DATABASE,
    password: process.env.DB_PASSWORD
});

module.exports = db;