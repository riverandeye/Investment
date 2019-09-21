import React, { useEffect, useRef, useContext } from "react";
import classes from './Cockpit.module.css'
import AuthContext from '../../context/auth-context'

const Cockpit = (props) => {
    const toggleBtnRef = useRef();
    const context = useContext(AuthContext);

    useEffect(()=>{
        console.log('[Cockpit.js] useEffect');
        toggleBtnRef.current.click();
        const timer = setTimeout(()=>{
            alert("Saved data to Cloud");
        }, 1000)
        return ()=>{
            clearTimeout(timer);
            console.log("[Cockpit.js] cleanup work in useEffect");
        }
    }, []);

    let btnClass = '';
    if (props.showPersons){
        btnClass = classes.Red;
    }
    const assignedClasses = [];
    if(props.personslength <= 2){
        assignedClasses.push(classes.red);
    }

    if(props.personslength <= 1){
        assignedClasses.push( classes.bold );
    }
    
   return (
       <div className={classes.Cockpit}>
        <h1>{props.title}</h1>
          <p className={assignedClasses.join(' ')}>This is really Working!</p>
          <button onClick={props.clicked} ref = {toggleBtnRef}>Toggle</button>
          <button onClick={context.login}>Log in</button>
       </div>
   );
};

export default React.memo(Cockpit);