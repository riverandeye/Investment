const mysql = require('mysql2');
require('dotenv').config({path : `../../.env`});
const util = require("util");

const db = mysql.createPool({
    host: process.env.DB_HOST,
    user: process.env.DB_USER,
    port: process.env.DB_PORT,
    database: process.env.DB_DATABASE,
    password: process.env.DB_PASSWORD
});

db.query = util.promisify(db.query);

module.exports = db;