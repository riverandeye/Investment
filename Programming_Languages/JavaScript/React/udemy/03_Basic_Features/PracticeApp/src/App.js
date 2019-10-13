import React, {useState} from 'react';
import logo from './logo.svg';
import './App.css';
import UserInput from './UserInput/UserInput'
import UserOutput from './UserOutput/UserOutput'

function App() {
  const [userName, stateuserName] = useState({
    user1:"James",
    user2:"John",
    user3:"Jart",
  })

  const eventHandler = (event)=>{
    stateuserName({
      user1: event.target.value,
      user2:"John",
      user3:"Jart",
    })
  }

  return (
    <div className="App">
      <UserInput getName={eventHandler} value={userName.user1}/>
      <UserOutput username={userName.user1}></UserOutput>
      <UserOutput username={userName.user2}></UserOutput>
      <UserOutput username={userName.user3}></UserOutput>
    </div>
  );
}

export default App;
