const express = require('express');
const OAuth = express.Router();
const { login } = require('../../controller/auth');
const axios = require('axios');

OAuth.get('/login', (req, res, next) => {
  res.redirect(
    `https://github.com/login/oauth/authorize?client_id=${process.env.CLIENT_ID}`
  );
});

OAuth.get('/login/cb', async (req, res, next) => {
  const AuthorizeToken = req.query.code; // Authorize code
  const response = await axios({
    method: 'post',
    url: `https://github.com/login/oauth/access_token?client_id=${process.env.CLIENT_ID}&client_secret=${process.env.CLIENT_SECRET}&code=${AuthorizeToken}`,
    headers: {
      accept: 'application/json'
    }
  });

  const AccessToken = response.data.access_token;

  const response2 = await axios({
    method: 'get',
    headers: {
      Authorization: `token ${AccessToken}`
    },
    url: `https://api.github.com/user`
  }).catch(e => {
    console.log(e);
  });
  res.send(response2.data);
});

OAuth.get('/me', (req, res, next) => {
  res.send('토큰의 주인');
});

OAuth.get('/refresh', (req, res, next) => {
  res.send('새로운 토큰');
});

module.exports = OAuth;
