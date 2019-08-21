/*
GAME RULES:

- The game has 2 players, playing in rounds
- In each turn, a player rolls a dice as many times as he whishes. Each result get added to his ROUND score
- BUT, if the player rolls a 1, all his ROUND score gets lost. After that, it's the next player's turn
- The player can choose to 'Hold', which means that his ROUND score gets added to his GLBAL score. After that, it's the next player's turn
- The first player to reach 100 points on GLOBAL score wins the game

*/

var score, roundScore, activePlayer, gamePlaying; // 0 = first player, 1 = second player
var dice = Math.floor(Math.random() * 6) + 1;

// document.querySelector('#current-' + activePlayer).textContent = dice;

init();
// document.querySelector('#current-'+activePlayer).innerHTML = '<em>' + dice + '</em>'; // textContent는 text 그대로, HTML넣으려면 innerHTML
// document.querySelector('.dice').style.display = 'none'; // class 가져와서, 해당 style.display 없애기 가능. style은 해당 클래스의 CSS에 접근한거고, display는 안보이게 한거고.
document.querySelector('.btn-roll').addEventListener('click', btn);

function btn(){
    if(!gamePlaying) return;
    var dice = Math.floor(Math.random() * 6) + 1;
    var diceDom = document.querySelector('.dice');
    diceDom.style.display = 'block'; // block 영역으로 보이게 만든다.
    diceDom.src = 'dice-' + dice + '.png';
    if(dice !== 1){
        roundScore += dice;
        document.querySelector('#current-' + activePlayer).textContent = roundScore;
    }
    else{
        nextPlayer();
    }
}

document.querySelector('.btn-hold').addEventListener('click', ()=>{
    if(!gamePlaying) return;
    score[activePlayer] += roundScore;
    document.querySelector(`#score-${activePlayer}`).textContent = score[activePlayer];

    if(score[activePlayer] >= 100){
        document.getElementById(`name-${activePlayer}`).textContent = 'Winner!!';
        document.querySelector('.dice').style.display = 'none';
        document.querySelector(`.player-${activePlayer}-panel`).classList.add('winner');
        document.querySelector(`.player-${activePlayer}-panel`).classList.remove('active');
        gamePlaying = false;
    }
    else nextPlayer();
});

function nextPlayer(){
    roundScore = 0;
    document.getElementById(`current-${activePlayer}`).textContent = `${roundScore}`;
    activePlayer === 0 ? activePlayer = 1 : activePlayer = 0;
    document.querySelector(`.player-0-panel`).classList.toggle('active');
    document.querySelector(`.player-1-panel`).classList.toggle('active');
    document.querySelector('.dice').style.display = 'none';
}

document.querySelector(`.btn-new`).addEventListener('click', init)

function init(){
    score = [0,0];
    activePlayer = 0;
    roundScore = 0;
    gamePlaying = true;
    document.getElementById('score-0').textContent = '0';
    document.getElementById('score-1').textContent = '0';
    document.getElementById('current-0').textContent = '0';
    document.getElementById('current-1').textContent = '0';
    document.getElementById('name-0').textContent = 'Player 1';
    document.getElementById('name-1').textContent = 'Player 2';
    document.querySelector(`.player-0-panel`).classList.remove('winner');
    document.querySelector(`.player-1-panel`).classList.remove('winner');
    document.querySelector(`.player-0-panel`).classList.remove('active');
    document.querySelector(`.player-1-panel`).classList.remove('active');
    document.querySelector(`.player-0-panel`).classList.add('active');
}