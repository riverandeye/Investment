import React from 'react';
import styles from './DrawerToggle.module.css';

const drawerToggle = props => (
  <div className={styles.DrawerToggle} onClick={props.clicked}>
    <div></div>
    <div></div>
    <div className={styles.Last}></div>
  </div>
);

export default drawerToggle;
