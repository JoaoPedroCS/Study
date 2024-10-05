const idpokemon = document.getElementById('pokemon-id');
const tipos = document.getElementById('types');
const altura = document.getElementById('height');
const peso = document.getElementById('weight');
const hp = document.getElementById('hp');
const ataque = document.getElementById('attack');
const imgsdiv = document.getElementById('sprite-container');
const defesa = document.getElementById('defense');
const specialAtaque = document.getElementById('special-attack');
const specialDefesa = document.getElementById('special-defense');
const velocidade = document.getElementById('speed');
const procuraBtn = document.getElementById('search-form');
const campoPesquisa = document.getElementById('search-input');
const nomepoke = document.getElementById('pokemon-name');

const getPokemon = async () => {
  try {
    const pokemonNameOrId = campoPesquisa.value.toLowerCase();
    const response = await fetch(
      `https://pokeapi-proxy.freecodecamp.rocks/api/pokemon/${pokemonNameOrId}`
    );
    const data = await response.json();

    nomepoke.textContent = `${data.name.toUpperCase()}`;
    idpokemon.textContent = `#${data.id}`;
    peso.textContent = `Weight: ${data.weight}`;
    altura.textContent = `Height: ${data.height}`;
    imgsdiv.innerHTML = `
      <img id="sprite" src="${data.sprites.front_default}" alt="${data.name} front default sprite">
    `;

    hp.textContent = data.stats[0].base_stat;
    ataque.textContent = data.stats[1].base_stat;
    defesa.textContent = data.stats[2].base_stat;
    specialAtaque.textContent = data.stats[3].base_stat;
    specialDefesa.textContent = data.stats[4].base_stat;
    velocidade.textContent = data.stats[5].base_stat;

    tipos.innerHTML = data.types
      .map(obj => `<span class="type ${obj.type.name}">${obj.type.name}</span>`)
      .join('');
  } catch (err) {
    resetaTela();
    alert('Pokémon not found');
    console.log(`Pokémon not found: ${err}`);
  }
};

const resetaTela = () => {
  const sprite = document.getElementById('sprite');
  if (sprite) sprite.remove();

  nomepoke.textContent = '';
  idpokemon.textContent = '';
  tipos.innerHTML = '';
  altura.textContent = '';
  peso.textContent = '';
  hp.textContent = '';
  ataque.textContent = '';
  defesa.textContent = '';
  specialAtaque.textContent = '';
  specialDefesa.textContent = '';
  velocidade.textContent = '';
};

procuraBtn.addEventListener('submit', e => {
  e.preventDefault();
  getPokemon();
});

const searchInput = document.getElementById('input-search');
const searchButton = document.getElementById('button-search');
const resultDiv = document.getElementById('poke-result');
const statsDiv = document.getElementById('poke-stats');


searchInput.addEventListener('keypress', (event) => {
    if (event.key === 'Enter') {
        searchButton.click();
    }
});
searchButton.addEventListener('click', () => {
    const searchValue = searchInput.value.toLowerCase();
    const apiURL = `https://pokeapi.co/api/v2/pokemon/${searchValue}`;
    fetch(apiURL)
        .then(response => {
            if (!response.ok) {
                alert('Pokémon not found');;
            }
            return response.json();
        })
        .then(data => {
            const { name, id, height, weight, base_experience, sprites, stats, types } = data;

            const { front_default, back_default, front_shiny, back_shiny } = sprites;

            const baseStats = stats.map(stat => ({
                name: stat.stat.name,
                value: stat.base_stat
            }));

            const typeNames = types.map(type => type.type.name);

            renderPokemon(name, id, height, weight, base_experience, front_default, back_default, front_shiny, back_shiny, baseStats, typeNames);
        })
        .catch(error => {
            return;
        })});

const renderPokemon = (name, id, height, weight, base_experience, front_default, back_default, front_shiny, back_shiny, baseStats, typeNames) => {
    const typeHTML = typeNames.map((type, index) => `
        <p class="type type-${type.toLowerCase()} ${index === 1 && typeNames.length === 1 ? 'hidden' : ''}">${type}</p>
    `).join('');

    const pokemonHTML = `
        <h2 id="name-id">${name} #${id}</h2>
        <p id="peso-altura">Peso: ${weight} Altura: ${height}</p>
        <img id="poke-img" class="poke-sprite" src="${front_default}" alt="">
        <div class="types">
            ${typeHTML}
        </div>
    `;

    resultDiv.innerHTML = pokemonHTML;

    const statsHTML = `
        <p class="stat-title">Base</p>
        <p class="stat-title">Stats</p>
        <p>HP:</p>
        <p id="stat-HP">${baseStats.find(stat => stat.name === 'hp').value}</p>
        <p>Attack:</p>
        <p id="stat-Attack">${baseStats.find(stat => stat.name === 'attack').value}</p>
        <p>Defense:</p>
        <p id="stat-Defense">${baseStats.find(stat => stat.name === 'defense').value}</p>
        <p>Sp. Attack:</p>
        <p id="stat-Sp.Attack">${baseStats.find(stat => stat.name === 'special-attack').value}</p>
        <p>Sp. Defense:</p>
        <p id="stat-Sp.Defense">${baseStats.find(stat => stat.name === 'special-defense').value}</p>
        <p>Speed:</p>
        <p id="stat-Speed">${baseStats.find(stat => stat.name === 'speed').value}</p>
    `;

    statsDiv.innerHTML = statsHTML;
}
