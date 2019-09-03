import header from '../component/header.js'
import footer from '../component/footer.js'
import aboutContent from '../component/aboutContent.js'

const about = {
    render(){
        return `${header()}
        ${aboutContent()}
        ${footer()}`;
    },

    init(){

    }
}

export default about;