import React, {Component} from "react";
import './CharComponent.css';
const CharComponent = (props)=>{
    return(
        <div className="CharComponent" onClick={props.onClick}>
            {props.char}
        </div>
    )
}

export default CharComponent;