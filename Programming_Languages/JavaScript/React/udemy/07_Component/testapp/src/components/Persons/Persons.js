import React, {PureComponent} from 'react';
import Person from "./Person/Person";

class Persons extends PureComponent{

    static getDerivedStateFromProps(props, state){
        console.log("[Persons.js] getDerivedStateFromProps");
        return state;
    }

    getSnapshotBeforeUpdate(prevProps, prevState){
        console.log("[Persons.js] getSnapshotBeforeUpdate");
    }

    componentDidUpdate(){
        console.log("[Persons.js] componentDidUpdate");
    }

    componentWillUnmount(){
        console.log("[Persons.js] componentWillUnmount");
    }    

    render(){
        console.log("[Persons.js] render")
        return this.props.persons.map(
            (person, idx)=>{
                return <Person
                    key={person.id}
                    click={()=>this.props.clicked(idx)}
                    name={person.name} 
                    age={person.age}
                    changed={(event)=>this.props.changed(event, person.id)}/>
            }
        )
    }
}
export default Persons;
