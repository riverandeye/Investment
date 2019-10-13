import React from 'react';
import './Person.css'

const person = (props)=>{
    return (
    <div className="Person">
        <p onClick={props.click}>I'm {props.name}. I'm {props.age} years old!</p>
        <p>{props.children}</p>
        <input type='text' onChange={props.changed} value={props.name}></input>
    </div>
    )
} // for this binding

export default person;