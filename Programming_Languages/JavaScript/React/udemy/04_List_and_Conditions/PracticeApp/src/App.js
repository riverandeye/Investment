import React, {Component} from 'react';
import logo from './logo.svg';
import './App.css';
import ValidationComponent from './ValidationComponent/ValidationComponent';
import CharComponent from './CharComponent/CharComponent';

class App extends Component {
  state = {
    userInput:'',
  };

  inputStateHandler = (e)=>{
    this.setState({userInput:e.target.value});
  }

  clickeventHandler = (idx)=>{
    const text = this.state.userInput.split('');
    text.splice(idx,1);
    const newText = text.join('');
    this.setState({userInput:newText});
  }

  render(){
    const res = [...this.state.userInput].map((item,idx)=>{
      return (
        <CharComponent char={item} key={idx} onClick={()=>this.clickeventHandler(idx)}></CharComponent>
      )
    })
    return (
      <div className="App">
        <input type='text' onChange={this.inputStateHandler} value={this.state.userInput}></input>
        <p>{this.state.userInput}</p>
        <ValidationComponent length={this.state.userInput.length}></ValidationComponent>
        {res}
      </div>
    );
  }
}

export default App;
