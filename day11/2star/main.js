const { initMap, solution } = require('./utils/readFile');

const mapa = initMap('input.txt');
// console.log(mapa);
const solution_output = solution("svr", mapa);
console.log(solution_output);