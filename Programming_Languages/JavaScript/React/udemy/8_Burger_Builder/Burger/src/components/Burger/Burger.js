import React, {Component} from 'react';
import classes from './Burger.module.css'
import BurgerIngredient from './BurgerIngredient/BurgerIngredient';
const burger = (props)=>{
    let transformedIngredients = Object.keys(props.ingredients).map(igKey => {
            return [ ...Array(props.ingredients[igKey])].map( (_ , i) => {
                return <BurgerIngredient key={igKey + i} type={igKey}/>
            });
        }).reduce(
            (acc,val)=>{
                return acc.concat(val);
            }
        , [])
    
    if(transformedIngredients.length === 0){
        transformedIngredients = <p>재료를 넣어주세요 :)</p>
    }
    return (
        <div className={classes.Burger}>
            <BurgerIngredient type='bread-top'/>
            {transformedIngredients}
            <BurgerIngredient type='bread-bottom'/>
        </div>
    );
}

export default burger;