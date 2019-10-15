require('dotenv').config({ path: __dirname + '/./../../../.env' });

const { Sequelize } = require('sequelize');
const mysql2 = require('mysql2');

const sequelize = new Sequelize(
  process.env.DB_DATABASE,
  process.env.DB_USER,
  process.env.DB_PASSWORD,
  {
    dialect: 'mysql',
    dialectModule: mysql2,
    host: process.env.DB_HOST,
    port: process.env.DB_PORT,
    pool: {
      max: 5,
      min: 1,
      acquire: 30000,
      idle: 10000
    }
  }
);

// DB 연결 테스트
sequelize
  .authenticate()
  .then(() => {
    console.log('Connection has been established successfully.');
  })
  .catch(err => {
    console.error('Unable to connect to the database:', err);
  });

module.exports = sequelize;
