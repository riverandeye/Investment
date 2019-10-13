import React from 'react';
import Aux from '../../../hoc/Aux';
import Button from '../../UI/Button/Button';

class orderSummary extends React.Component {
  render() {
    const ingredientSummary = Object.keys(this.props.ingredients).map(igKey => {
      return (
        <li key={igKey}>
          <span style={{ textTransform: 'capitalize' }}>{igKey}</span>:{' '}
          {this.props.ingredients[igKey]}
        </li>
      );
    });
    return (
      <Aux>
        <h3>주문 내역</h3>
        <p>첨가하신 재료는 다음과 같습니다.</p>
        <ul>{ingredientSummary}</ul>
        <p>
          <strong>총 가격 : {this.props.price.toFixed(0)}</strong>
        </p>
        <p>결제하시겠습니까?</p>
        <Button btnType="Danger" clicked={this.props.purchaseCancelled}>
          취소
        </Button>
        <Button btnType="Success" clicked={this.props.purchaseContinued}>
          동의
        </Button>
      </Aux>
    );
  }
}

export default orderSummary;
