import React from 'react'
import ReactDOM from 'react-dom'
import './index.css'

function Person(props){ // props param has all element
    return (
        <div class="person">
            <h1>{props.name}</h1>
            <p>Your age : {props.age}</p>
        </div>
    );
}

ReactDOM.render(<Person name ="Kwan" age = "28"/>, document.getElementById('root'))