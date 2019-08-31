import React, { Component, useState } from 'react';
import './App.css';
import Radium ,{ StyleRoot } from 'radium';
import Person from './Person/Person'

class App extends Component {
  state = {
    persons : [
      { id : "a", name : "Max", age : 28},
      { id : "b", name : "John", age : 15},
      { id : "c", name : "Doll", age : 2},
    ],
    showPerson:false,
  }

  nameChangeHandler = (event, id)=>{
    const personIdx = this.state.persons.findIndex((p)=>{
      return p.id === id;
    })

    const person = {...this.state.persons[personIdx]};

    person.name = event.target.value;

    const persons = [...this.state.persons];
    persons[personIdx] = person;

    this.setState(
      {persons : persons});
  }

  togglePersonsHandler = (event)=>{
    const doesShow = this.state.showPerson;
    this.setState({showPerson:!doesShow}); 
  }

  deletePersonHandler = (personIdx)=>{
    const persons = this.state.persons;
    persons.splice(personIdx, 1);
    this.setState({persons:persons});
  }

  render(){
    const style = {
      backgroundColor: 'green',
      color: 'white',
      font: 'inherit',
      border: '1x solid blue',
      padding: '8px',
      ':hover':{
        backgroundColor:'lightgreen',
        color: 'black'
      }
    }

    let persons = null;
    if(this.state.showPerson){
      persons = (
        <div>
          {this.state.persons.map((person, idx)=>{
            return <Person 
              key={person.id}
              click={()=>this.deletePersonHandler(idx)}
              name={person.name} 
              age={person.age}
              changed={(event)=>this.nameChangeHandler(event, person.id)}/>
          })}
        </div>
      )
      
      style.backgroundColor = "red";
      style[':hover'] = {
        backgroundColor:'salmon',
        color: 'black'
      }
    }

      let classes = [];
      if(this.state.persons.length <= 2) classes.push('red');
      if(this.state.persons.length <= 1) classes.push('bold');

      return (
        <StyleRoot>
          <div className="App">
            <h1>Hi, I'm a React App</h1>
            <p className={classes.join(' ')}>This is really Working!</p>
            <button style={style} onClick={()=>this.togglePersonsHandler()}>Toggle</button>
            {persons}
          </div>
        </StyleRoot>
    );
  }
}

export default Radium(App);