import React, { Component, useState } from 'react';
import './App.css';
import Person from './Person/Person'

class App extends Component {
  state = {
    persons : [
      { name : "Max", age : 28},
    ]
  }

  switchNameHandler = (newName) => {
    this.setState({
      persons : [
        { name : newName, age : Math.floor(Math.random() * 30)},
      ]
    },)
  }

  nameChangeHandler = (event)=>{
    this.setState({
      persons : [
        { name : event.target.value, age : Math.floor(Math.random() * 30)},
      ]
    },)
  }

  render(){
    const style = {
      backgroundColor: 'white',
      font: 'inherit',
      border: '1x solid blue',
      padding: '8px'
    }
      return (
      <div className="App">
        <h1>Hi, I'm a React App</h1>
        <button style={style} onClick={()=>this.switchNameHandler("badass")}>Switch Name</button>
        <Person 
          name={this.state.persons[0].name} 
          age={this.state.persons[0].age}
          click={()=>this.switchNameHandler("awesomeMan")}
          changed={this.nameChangeHandler}/>
      </div>
    );
  }
}

export default App;

