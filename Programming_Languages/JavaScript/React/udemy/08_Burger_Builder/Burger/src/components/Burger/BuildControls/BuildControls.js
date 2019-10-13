import React from 'react';
import style from './BuildControls.module.css'
import BuildControl from './BuildControl/BuildControl';

const controls = [
    {label : '야채', type: 'salad'},
    {label : '베이컨', type: 'bacon'},
    {label : '치즈', type: 'cheese'},
    {label : '고기', type: 'meat'},
];

const buildControls = (props)=>(
    <div className={style.BuildControls}>
        <p><strong>현재 가격:</strong> {props.price.toFixed(0)}원</p>
        {controls.map(ctrl =>(
            <BuildControl 
                key={ctrl.label} 
                label={ctrl.label} 
                added={() => props.ingredientAdded(ctrl.type)}
                removed={()=>props.ingredientRemoved(ctrl.type)}
                disabled={props.disabled[ctrl.type]}/>
        ))}
        <button className={style.OrderButton}
                disabled={!props.purchasable}
                onClick={props.ordered}>주문하기</button>
    </div>
)

export default buildControls;