import React, { Component } from 'react';
import PropTypes from 'prop-types';

import Classes from './Person.module.css'
import WithClass from '../../../hoc/WithClass'
import Aux from '../../../hoc/Auxiliary';
import AuthContext from '../../../context/auth-context'

class Person extends Component{
    constructor(props){
        super(props)
        this.inputElementRef = React.createRef();
    }

    static contextType = AuthContext;

    componentDidMount(){
        console.log('helloHellohello')
        this.inputElementRef.current.focus();
        console.log(this.inputElementRef);
    }

    render(){
    console.log("[Person.js] render")
    return (
    <Aux>
        {this.context.authenticated ? <p>Authenticated</p> : <p>Please Log in!</p>}
        <p onClick={this.props.click}>I'm {this.props.name}. I'm {this.props.age} years old!</p>
        <p>{this.props.children}</p>
        <input type='text' ref={this.inputElementRef} onChange={this.props.changed} value={this.props.name}></input>
    </Aux>
    )
    }
} // for this binding

Person.propTypes = {
    click : PropTypes.func,
    name : PropTypes.string,
    age : PropTypes.number,
    changed : PropTypes.func
}

export default WithClass(Person, Classes.Person);