import React from "react";

const ValidationComponent = (props)=>{
    
    let result = "Text long enough";
    if(props.length < 5){
        result = "Text too Short";
    }
    
    return (
        <p>{result}</p>
    );
}

export default ValidationComponent;