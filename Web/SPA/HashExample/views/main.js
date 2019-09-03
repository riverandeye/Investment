import header from '../component/header.js'
import footer from '../component/footer.js'
import mainContent from '../component/mainContent.js'

const main = {

    render(){
        console.log(header());
        return `${header()}
        ${mainContent()}
        ${footer()}`;
    },

    init(){
        
    }
}

export default main;