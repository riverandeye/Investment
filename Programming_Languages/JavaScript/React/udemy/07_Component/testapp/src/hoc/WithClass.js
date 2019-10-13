import React from 'react';

const WithClass = (WrappedComponents, className) => {
    
    return props => (
        <div className={className}>
            <WrappedComponents {...props}/>
        </div>
    );
}

export default WithClass;