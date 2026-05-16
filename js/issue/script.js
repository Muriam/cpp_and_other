// Получаем элементы DOM
const cityRadios = document.querySelectorAll('input[name="city"]');
const cityInfoDiv = document.getElementById('city-info');

let currentLoadController = null;

function getSelectedCity() {
    const checked = document.querySelector('input[name="city"]:checked');
    return checked ? checked.value : null;
}

// Данные из скрытых блоков в index.html (работает при file://)
function getCityHTMLFromTemplate(cityName) {
    const template = document.getElementById(`city-template-${cityName}`);
    if (!template) {
        return null;
    }
    return template.innerHTML;
}

function renderCityHTML(cityHTML) {
    const tempDiv = document.createElement('div');
    tempDiv.innerHTML = cityHTML;

    const cityCard = tempDiv.querySelector('.city-card');
    if (cityCard) {
        cityInfoDiv.innerHTML = cityCard.outerHTML;
        return;
    }

    const bodyContent = tempDiv.querySelector('body');
    if (bodyContent) {
        cityInfoDiv.innerHTML = bodyContent.innerHTML;
        return;
    }

    cityInfoDiv.innerHTML = cityHTML;
}

async function loadCityHTML(cityName, signal) {
    // При открытии файла напрямую fetch заблокирован — берём шаблон
    if (window.location.protocol === 'file:') {
        const html = getCityHTMLFromTemplate(cityName);
        if (html) {
            return html;
        }
        throw new Error('Шаблон не найден');
    }

    const url = new URL(`data/${cityName}.html`, window.location.href);
    const response = await fetch(url, { signal });

    if (!response.ok) {
        throw new Error(`HTTP ошибка: ${response.status}`);
    }

    return response.text();
}

async function showCityInfo(cityName) {
    if (currentLoadController) {
        currentLoadController.abort();
    }

    currentLoadController = new AbortController();
    const { signal } = currentLoadController;

    let cityHTML;

    try {
        cityHTML = await loadCityHTML(cityName, signal);
    } catch (error) {
        if (error.name === 'AbortError') {
            return;
        }

        cityHTML = getCityHTMLFromTemplate(cityName);
        if (!cityHTML) {
            console.error('Ошибка загрузки HTML:', error);
            if (getSelectedCity() !== cityName) {
                return;
            }
            cityInfoDiv.innerHTML = `
                <div style="color: red; padding: 20px;">
                    <h3>Ошибка загрузки данных</h3>
                    <p>Не удалось загрузить информацию о городе "${cityName}"</p>
                    <p>Проверьте файл: data/${cityName}.html</p>
                </div>
            `;
            return;
        }
    }

    if (getSelectedCity() !== cityName) {
        return;
    }

    renderCityHTML(cityHTML);
}

function resetInfo() {
    if (currentLoadController) {
        currentLoadController.abort();
        currentLoadController = null;
    }
    cityInfoDiv.innerHTML = `
        <div class="placeholder">
            <div class="placeholder-icon">🗺️</div>
            <p>Выберите город для отображения информации</p>
        </div>
    `;
}

cityRadios.forEach(radio => {
    radio.addEventListener('change', function() {
        if (this.checked) {
            showCityInfo(this.value);
        } else {
            const anyChecked = Array.from(cityRadios).some(r => r.checked);
            if (!anyChecked) {
                resetInfo();
            }
        }
    });
});

window.addEventListener('load', resetInfo);
