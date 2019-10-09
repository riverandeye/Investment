import axios from 'axios';

const instance = axios.create({
  baseURL: `https://riverandeye-1560397510769.firebaseio.com/`
});

export default instance;
