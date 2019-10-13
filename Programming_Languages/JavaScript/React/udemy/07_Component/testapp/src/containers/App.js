import React, { Component, useState } from 'react';
import Classes from './App.module.css';

import Persons from '../components/Persons/Persons';
import Cockpit from '../components/Cockpit/Cockpit';
import WithClass from "../hoc/WithClass";
import Aux from '../hoc/Auxiliary';
import AuthContext from '../context/auth-context'

class App extends Component {
  constructor(props){
    super(props);
    console.log('[App.js] Constructor');
    this.state = {
      persons : [
        { id : "a", name : "Max", age : 28},
        { id : "b", name : "John", age : 15},
        { id : "c", name : "Doll", age : 2},
      ],
      showPersons:false,
      showCockpit:true,
      changeCounter : 0,
      authenticated : false,
    }
  }

  static getDerivedStateFromProps(props, state){
    console.log("[App.js] getDerivedStateFromProps, ", props);
    return state;
  }

  componentDidMount(){
    console.log("[App.js] componentDidMount");
  }

  shouldComponentUpdate(nextProps, nextState){
    console.log("[App.js] shouldComponentUpdate");
    return true;
  }

  componentDidUpdate(){
    console.log("[App.js] componentDidUpdate");
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
      (prevState, props)=>{
        return {
          persons : persons,
          changeCounter : prevState.changeCounter + 1,
        }

      }
    )
  }

  togglePersonsHandler = (event)=>{
    const doesShow = this.state.showPersons;
    this.setState({showPersons:!doesShow}); 
  }

  deletePersonHandler = (personIdx)=>{
    const persons = this.state.persons;
    persons.splice(personIdx, 1);
    this.setState({persons:persons});
  }

  loginHandler = ()=>{
    this.setState({authenticated : true});
    console.log(this.state);
  }

  render(){
    console.log("[App.js] render")
    const style = {
      backgroundColor: 'green',
      color: 'white',
      font: 'inherit',
      border: '1x solid blue',
      padding: '8px'
    }

    let persons = null;
    if(this.state.showPersons){
      persons = <Persons
            showPersons = {this.state.showPersons}
            persons = {this.state.persons}
            clicked = {this.deletePersonHandler}
            changed = {this.nameChangeHandler}
            isAuthenticated = {this.state.authenticated}
          />
      style.backgroundColor = "red";
    }
    
    return (
      <Aux>
          <button onClick={()=>{this.setState({showCockpit:!this.state.showCockpit})}}>remove Cockpit</button>
          <AuthContext.Provider 
            value={{authenticated: this.state.authenticated, login: this.loginHandler}}>
          
          {this.state.showCockpit?<Cockpit
            title= {this.props.appTitle}
            showPersons = {this.state.showPersons}
            personslength = {this.state.persons.length}
            clicked = {this.togglePersonsHandler}
          />:null}
          {persons}
          
          </AuthContext.Provider>
      </Aux>
    );
  }
}

export default WithClass(App, Classes.App);