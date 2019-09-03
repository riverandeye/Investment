import main from './views/main.js';
import about from './views/about.js';
import contact from './views/contact.js';

const routes = {
    '/': {
        component: main,
        title: 'Homepage'
    },

    'home': {
        component: main,
        title: 'Homepage'
    },
    'about': {
        component: about,
        title: 'About Myself'
    },

    'contact': {
        component: contact,
        title: 'Contact to me!'
    }
}

const getCurrentPath = () => {
    const hashPath = window.location.hash.split("#");
    return hashPath[1] ? hashPath[1] : '/';
}

const getRoute = () => {
    const path = getCurrentPath();
    const route = routes[path];
    return route ? route : routes['/404'];
}

const router = async () => {
    const {
        component,
        title
    } = getRoute();
    document.title = title;

    const page = component;
    const view = page.render();
    const root = document.getElementById('root');
    root.innerHTML = view;

    page.init();
}

window.addEventListener('DOMContentLoaded', router);
window.addEventListener('hashchange', router);