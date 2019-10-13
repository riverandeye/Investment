import React from 'react';
import NavigationItem from './NavigationItem/NavigationItem';
import styles from './NavigationItems.module.css';
const navigationItems = props => (
  <ul className={styles.NavigationItems}>
    <NavigationItem active link="/">
      Burger Builder
    </NavigationItem>
    <NavigationItem active link="/">
      Checkout
    </NavigationItem>
  </ul>
);

export default navigationItems;
