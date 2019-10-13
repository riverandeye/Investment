import React from 'react';
import './UserInput.css'

const UserInput = (props)=>{
    return (
        <div className="textbox">
        <input type='text' onChange={props.getName} value={props.value}></input>
        </div>
    )
}

export default UserInput;