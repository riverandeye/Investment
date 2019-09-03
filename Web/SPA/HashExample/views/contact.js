import header from '../component/header.js'
import footer from '../component/footer.js'
import contactContent from '../component/contactContent.js'

const contact = {
    render(){
        return `${header()}
        ${contactContent()}
        ${footer()}`;
    },

    init(){

    }
}

export default contact;