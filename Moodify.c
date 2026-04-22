<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Moodify – Emotion-Based Music</title>
  <link href="https://fonts.googleapis.com/css2?family=Circular+Std:wght@400;700&family=Montserrat:wght@400;600;700;900&display=swap" rel="stylesheet" />
  <script src="https://cdnjs.cloudflare.com/ajax/libs/react/18.2.0/umd/react.production.min.js"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/react-dom/18.2.0/umd/react-dom.production.min.js"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/babel-standalone/7.23.2/babel.min.js"></script>
  <style>
    *, *::before, *::after { box-sizing: border-box; margin: 0; padding: 0; }

    :root {
      --sp-green: #1DB954;
      --sp-green-hover: #1ed760;
      --sp-black: #121212;
      --sp-dark: #181818;
      --sp-card: #282828;
      --sp-card-hover: #333333;
      --sp-light: #b3b3b3;
      --sp-white: #FFFFFF;
      --sp-sidebar: #000000;
      --happy: #FFD700;
      --sad: #4A90D9;
      --chill: #7ED9A7;
      --party: #FF6B6B;
      --romantic: #FF85A1;
      --angry: #FF4500;
      --font: 'Montserrat', sans-serif;
    }

    html, body { height: 100%; background: var(--sp-black); color: var(--sp-white); font-family: var(--font); overflow: hidden; }

    #root { height: 100%; }

    /* Scrollbar */
    ::-webkit-scrollbar { width: 6px; }
    ::-webkit-scrollbar-track { background: transparent; }
    ::-webkit-scrollbar-thumb { background: #535353; border-radius: 3px; }

    /* ─── LOGIN PAGE ─── */
    .login-page {
      min-height: 100vh;
      background: linear-gradient(135deg, #0a0a0a 0%, #1a1a2e 50%, #0a0a0a 100%);
      display: flex;
      align-items: center;
      justify-content: center;
      position: relative;
      overflow: hidden;
    }
    .login-page::before {
      content: '';
      position: absolute;
      inset: 0;
      background: radial-gradient(ellipse at 30% 50%, rgba(29,185,84,0.12) 0%, transparent 60%),
                  radial-gradient(ellipse at 70% 20%, rgba(255,107,107,0.08) 0%, transparent 50%);
      pointer-events: none;
    }
    .login-orbs {
      position: absolute;
      inset: 0;
      pointer-events: none;
      overflow: hidden;
    }
    .orb {
      position: absolute;
      border-radius: 50%;
      filter: blur(80px);
      opacity: 0.15;
      animation: floatOrb 8s ease-in-out infinite;
    }
    .orb1 { width: 400px; height: 400px; background: var(--sp-green); top: -100px; left: -100px; animation-delay: 0s; }
    .orb2 { width: 300px; height: 300px; background: #4A90D9; bottom: -80px; right: -80px; animation-delay: 3s; }
    .orb3 { width: 200px; height: 200px; background: #FFD700; top: 50%; left: 50%; animation-delay: 5s; }
    @keyframes floatOrb {
      0%, 100% { transform: translate(0,0) scale(1); }
      50% { transform: translate(20px, -20px) scale(1.05); }
    }
    .login-box {
      position: relative;
      z-index: 10;
      width: 100%;
      max-width: 440px;
      background: rgba(24,24,24,0.95);
      border: 1px solid rgba(255,255,255,0.08);
      border-radius: 16px;
      padding: 48px 40px 40px;
      backdrop-filter: blur(20px);
      box-shadow: 0 32px 80px rgba(0,0,0,0.6);
      animation: slideUp 0.5s ease;
    }
    @keyframes slideUp {
      from { opacity: 0; transform: translateY(30px); }
      to   { opacity: 1; transform: translateY(0); }
    }
    .login-logo {
      text-align: center;
      margin-bottom: 32px;
    }
    .login-logo svg { width: 48px; height: 48px; }
    .login-logo h1 {
      font-size: 28px;
      font-weight: 900;
      letter-spacing: -0.5px;
      margin-top: 10px;
      background: linear-gradient(135deg, var(--sp-white), var(--sp-green));
      -webkit-background-clip: text;
      -webkit-text-fill-color: transparent;
    }
    .login-logo p { color: var(--sp-light); font-size: 13px; margin-top: 4px; }
    .login-divider { text-align: center; color: var(--sp-light); font-size: 12px; font-weight: 600; letter-spacing: 1px; text-transform: uppercase; margin: 24px 0; position: relative; }
    .login-divider::before, .login-divider::after {
      content: '';
      position: absolute;
      top: 50%;
      width: 40%;
      height: 1px;
      background: rgba(255,255,255,0.1);
    }
    .login-divider::before { left: 0; }
    .login-divider::after { right: 0; }
    .login-input-group { margin-bottom: 14px; }
    .login-input-group label { display: block; font-size: 12px; font-weight: 700; color: var(--sp-white); letter-spacing: 0.5px; margin-bottom: 6px; text-transform: uppercase; }
    .login-input-group input {
      width: 100%;
      padding: 13px 16px;
      background: rgba(255,255,255,0.07);
      border: 1px solid rgba(255,255,255,0.12);
      border-radius: 6px;
      color: var(--sp-white);
      font-size: 14px;
      font-family: var(--font);
      outline: none;
      transition: border-color 0.2s, background 0.2s;
    }
    .login-input-group input:focus {
      border-color: var(--sp-white);
      background: rgba(255,255,255,0.1);
    }
    .login-input-group input::placeholder { color: rgba(255,255,255,0.35); }
    .btn-spotify {
      width: 100%;
      padding: 14px;
      background: var(--sp-green);
      color: var(--sp-black);
      border: none;
      border-radius: 50px;
      font-size: 14px;
      font-weight: 700;
      font-family: var(--font);
      letter-spacing: 1.5px;
      text-transform: uppercase;
      cursor: pointer;
      transition: all 0.2s;
      margin-top: 8px;
    }
    .btn-spotify:hover { background: var(--sp-green-hover); transform: scale(1.02); }
    .login-toggle { text-align: center; margin-top: 20px; font-size: 13px; color: var(--sp-light); }
    .login-toggle a { color: var(--sp-white); text-decoration: underline; cursor: pointer; font-weight: 600; }
    .login-toggle a:hover { color: var(--sp-green); }
    .spotify-btn-outline {
      width: 100%;
      padding: 12px;
      background: transparent;
      border: 1px solid rgba(255,255,255,0.25);
      border-radius: 50px;
      color: var(--sp-white);
      font-size: 13px;
      font-weight: 600;
      font-family: var(--font);
      cursor: pointer;
      display: flex;
      align-items: center;
      justify-content: center;
      gap: 10px;
      transition: all 0.2s;
      margin-bottom: 10px;
    }
    .spotify-btn-outline:hover { background: rgba(255,255,255,0.07); border-color: rgba(255,255,255,0.4); }

    /* ─── APP LAYOUT ─── */
    .app-layout {
      display: grid;
      grid-template-columns: 240px 1fr;
      grid-template-rows: 1fr 90px;
      height: 100vh;
      background: var(--sp-black);
    }

    /* ─── SIDEBAR ─── */
    .sidebar {
      grid-row: 1 / 2;
      background: var(--sp-sidebar);
      padding: 24px 0;
      display: flex;
      flex-direction: column;
      overflow-y: auto;
      gap: 0;
    }
    .sidebar-logo {
      padding: 0 24px 28px;
      display: flex;
      align-items: center;
      gap: 10px;
    }
    .sidebar-logo svg { width: 32px; height: 32px; }
    .sidebar-logo span { font-size: 20px; font-weight: 900; letter-spacing: -0.5px; }
    .nav-section { padding: 0 0 20px; }
    .nav-label { padding: 14px 24px 6px; font-size: 11px; font-weight: 700; color: var(--sp-light); letter-spacing: 1.5px; text-transform: uppercase; }
    .nav-item {
      display: flex;
      align-items: center;
      gap: 14px;
      padding: 10px 24px;
      color: var(--sp-light);
      font-size: 14px;
      font-weight: 600;
      cursor: pointer;
      transition: color 0.15s;
      position: relative;
      border-radius: 0;
    }
    .nav-item:hover { color: var(--sp-white); }
    .nav-item.active { color: var(--sp-white); }
    .nav-item.active::before { content: ''; position: absolute; left: 0; top: 4px; bottom: 4px; width: 3px; background: var(--sp-green); border-radius: 0 2px 2px 0; }
    .nav-icon { width: 20px; height: 20px; flex-shrink: 0; }
    .sidebar-divider { height: 1px; background: rgba(255,255,255,0.06); margin: 8px 24px; }
    .playlist-list { flex: 1; overflow-y: auto; padding: 0 0 10px; }
    .playlist-item {
      padding: 8px 24px;
      font-size: 14px;
      color: var(--sp-light);
      cursor: pointer;
      white-space: nowrap;
      overflow: hidden;
      text-overflow: ellipsis;
      transition: color 0.15s;
    }
    .playlist-item:hover { color: var(--sp-white); }
    .playlist-item.active { color: var(--sp-white); }

    /* ─── MAIN CONTENT ─── */
    .main-content {
      grid-row: 1 / 2;
      overflow-y: auto;
      background: linear-gradient(180deg, #1a3a2a 0%, var(--sp-black) 340px);
      position: relative;
    }
    .main-header {
      position: sticky;
      top: 0;
      z-index: 100;
      padding: 16px 32px;
      display: flex;
      align-items: center;
      justify-content: space-between;
      background: rgba(0,0,0,0);
      transition: background 0.3s;
    }
    .main-header.scrolled { background: rgba(0,0,0,0.7); backdrop-filter: blur(10px); }
    .header-nav { display: flex; gap: 8px; }
    .header-nav-btn {
      width: 32px; height: 32px;
      background: rgba(0,0,0,0.5);
      border: none;
      border-radius: 50%;
      color: var(--sp-white);
      font-size: 16px;
      cursor: pointer;
      display: flex; align-items: center; justify-content: center;
      transition: background 0.2s;
    }
    .header-nav-btn:hover { background: rgba(255,255,255,0.1); }
    .header-user {
      display: flex; align-items: center; gap: 10px;
      background: rgba(0,0,0,0.4);
      border-radius: 50px;
      padding: 4px 8px 4px 4px;
      cursor: pointer;
      transition: background 0.2s;
    }
    .header-user:hover { background: rgba(255,255,255,0.1); }
    .avatar {
      width: 28px; height: 28px;
      background: linear-gradient(135deg, var(--sp-green), #158040);
      border-radius: 50%;
      display: flex; align-items: center; justify-content: center;
      font-size: 12px; font-weight: 700;
    }
    .header-user span { font-size: 13px; font-weight: 700; }

    .main-body { padding: 0 32px 32px; }

    /* Hero Mood Banner */
    .mood-hero {
      padding: 40px 0 32px;
    }
    .mood-hero h2 { font-size: 32px; font-weight: 900; margin-bottom: 8px; }
    .mood-hero p { color: var(--sp-light); font-size: 15px; }
    .mood-grid {
      display: grid;
      grid-template-columns: repeat(3, 1fr);
      gap: 12px;
      margin-top: 24px;
    }
    .mood-card {
      padding: 20px;
      border-radius: 12px;
      cursor: pointer;
      position: relative;
      overflow: hidden;
      aspect-ratio: 1.8;
      display: flex;
      align-items: flex-end;
      transition: transform 0.2s, box-shadow 0.2s;
    }
    .mood-card:hover { transform: scale(1.03); box-shadow: 0 12px 40px rgba(0,0,0,0.4); }
    .mood-card.active { outline: 3px solid var(--sp-white); outline-offset: 2px; }
    .mood-card::before {
      content: '';
      position: absolute;
      inset: 0;
      background: linear-gradient(135deg, currentColor 0%, transparent 100%);
      opacity: 0.5;
    }
    .mood-card .mood-emoji {
      position: absolute;
      top: 12px;
      right: 16px;
      font-size: 36px;
      filter: drop-shadow(0 2px 8px rgba(0,0,0,0.4));
      animation: bounceEmoji 2s ease-in-out infinite;
    }
    @keyframes bounceEmoji {
      0%, 100% { transform: translateY(0); }
      50% { transform: translateY(-5px); }
    }
    .mood-card-info { position: relative; z-index: 2; }
    .mood-card-info h3 { font-size: 18px; font-weight: 800; text-shadow: 0 2px 8px rgba(0,0,0,0.5); }
    .mood-card-info p { font-size: 12px; opacity: 0.85; text-shadow: 0 1px 4px rgba(0,0,0,0.5); }
    .mood-happy  { background: linear-gradient(135deg, #b8860b, #ffd700); color: white; }
    .mood-sad    { background: linear-gradient(135deg, #1a3a6e, #4A90D9); color: white; }
    .mood-chill  { background: linear-gradient(135deg, #1a5c3a, #7ED9A7); color: white; }
    .mood-party  { background: linear-gradient(135deg, #8b1a1a, #FF6B6B); color: white; }
    .mood-romantic { background: linear-gradient(135deg, #8b2252, #FF85A1); color: white; }
    .mood-angry  { background: linear-gradient(135deg, #5c1a00, #FF4500); color: white; }

    /* ─── SECTION HEADER ─── */
    .section-header {
      display: flex;
      align-items: center;
      justify-content: space-between;
      margin: 32px 0 16px;
    }
    .section-header h3 { font-size: 22px; font-weight: 800; }
    .section-header a { font-size: 12px; color: var(--sp-light); font-weight: 700; letter-spacing: 1px; text-transform: uppercase; cursor: pointer; transition: color 0.15s; }
    .section-header a:hover { color: var(--sp-white); text-decoration: underline; }

    /* ─── SONG CARDS GRID ─── */
    .song-grid {
      display: grid;
      grid-template-columns: repeat(auto-fill, minmax(170px, 1fr));
      gap: 16px;
    }
    .song-card {
      background: var(--sp-card);
      border-radius: 8px;
      padding: 16px;
      cursor: pointer;
      transition: background 0.2s, transform 0.15s;
      position: relative;
      group: true;
    }
    .song-card:hover { background: var(--sp-card-hover); }
    .song-card:hover .play-btn-overlay { opacity: 1; transform: translateY(0); }
    .song-art {
      width: 100%;
      aspect-ratio: 1;
      border-radius: 6px;
      margin-bottom: 14px;
      position: relative;
      overflow: hidden;
      box-shadow: 0 8px 24px rgba(0,0,0,0.5);
    }
    .song-art img { width: 100%; height: 100%; object-fit: cover; }
    .song-art-placeholder {
      width: 100%;
      height: 100%;
      display: flex;
      align-items: center;
      justify-content: center;
      font-size: 48px;
      border-radius: 6px;
    }
    .play-btn-overlay {
      position: absolute;
      bottom: 8px;
      right: 8px;
      width: 44px;
      height: 44px;
      background: var(--sp-green);
      border-radius: 50%;
      display: flex;
      align-items: center;
      justify-content: center;
      opacity: 0;
      transform: translateY(8px);
      transition: opacity 0.2s, transform 0.2s;
      box-shadow: 0 8px 20px rgba(0,0,0,0.4);
      border: none;
      cursor: pointer;
      color: var(--sp-black);
    }
    .play-btn-overlay:hover { background: var(--sp-green-hover); transform: translateY(0) scale(1.05) !important; }
    .song-card h4 { font-size: 14px; font-weight: 700; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; }
    .song-card p { font-size: 13px; color: var(--sp-light); margin-top: 4px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; }

    /* ─── NOW PLAYING ─── */
    .now-playing-bar {
      grid-column: 1 / -1;
      grid-row: 2;
      background: #181818;
      border-top: 1px solid rgba(255,255,255,0.08);
      display: grid;
      grid-template-columns: 1fr 2fr 1fr;
      align-items: center;
      padding: 0 16px;
      gap: 16px;
    }
    .np-track { display: flex; align-items: center; gap: 14px; min-width: 0; }
    .np-art {
      width: 56px; height: 56px;
      background: var(--sp-card);
      border-radius: 4px;
      flex-shrink: 0;
      display: flex; align-items: center; justify-content: center;
      font-size: 24px;
      overflow: hidden;
    }
    .np-art img { width: 100%; height: 100%; object-fit: cover; }
    .np-info { min-width: 0; }
    .np-info h4 { font-size: 13px; font-weight: 600; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; }
    .np-info p { font-size: 12px; color: var(--sp-light); margin-top: 2px; }
    .np-like { background: none; border: none; color: var(--sp-light); cursor: pointer; padding: 4px; transition: color 0.15s; }
    .np-like:hover { color: var(--sp-white); }
    .np-like.liked { color: var(--sp-green); }
    .np-controls { display: flex; flex-direction: column; align-items: center; gap: 8px; }
    .np-btns { display: flex; align-items: center; gap: 16px; }
    .ctrl-btn {
      background: none; border: none;
      color: var(--sp-light);
      cursor: pointer;
      display: flex; align-items: center; justify-content: center;
      transition: color 0.15s, transform 0.1s;
      padding: 4px;
    }
    .ctrl-btn:hover { color: var(--sp-white); transform: scale(1.08); }
    .ctrl-btn.active { color: var(--sp-green); }
    .play-pause-btn {
      width: 34px; height: 34px;
      background: var(--sp-white);
      border-radius: 50%;
      border: none;
      cursor: pointer;
      display: flex; align-items: center; justify-content: center;
      transition: transform 0.1s, background 0.15s;
      color: var(--sp-black);
    }
    .play-pause-btn:hover { transform: scale(1.06); background: #e8e8e8; }
    .progress-bar-row { width: 100%; display: flex; align-items: center; gap: 10px; }
    .time-label { font-size: 11px; color: var(--sp-light); min-width: 32px; }
    .progress-track {
      flex: 1;
      height: 4px;
      background: rgba(255,255,255,0.15);
      border-radius: 2px;
      cursor: pointer;
      position: relative;
      overflow: hidden;
    }
    .progress-fill {
      height: 100%;
      background: var(--sp-light);
      border-radius: 2px;
      transition: width 0.3s linear;
      position: relative;
    }
    .progress-track:hover .progress-fill { background: var(--sp-green); }
    .np-extra { display: flex; align-items: center; justify-content: flex-end; gap: 12px; }
    .volume-row { display: flex; align-items: center; gap: 8px; }
    .volume-track { width: 80px; height: 4px; background: rgba(255,255,255,0.15); border-radius: 2px; cursor: pointer; overflow: hidden; }
    .volume-fill { height: 100%; background: var(--sp-light); border-radius: 2px; transition: width 0.1s; }
    .volume-track:hover .volume-fill { background: var(--sp-green); }

    /* ─── PLAYLIST MODAL ─── */
    .modal-overlay {
      position: fixed;
      inset: 0;
      background: rgba(0,0,0,0.75);
      z-index: 1000;
      display: flex;
      align-items: center;
      justify-content: center;
      backdrop-filter: blur(4px);
      animation: fadeIn 0.2s ease;
    }
    @keyframes fadeIn { from { opacity: 0; } to { opacity: 1; } }
    .modal-box {
      background: #282828;
      border-radius: 12px;
      padding: 32px;
      width: 460px;
      max-width: 90vw;
      box-shadow: 0 24px 60px rgba(0,0,0,0.6);
      animation: slideUp 0.3s ease;
    }
    .modal-box h2 { font-size: 22px; font-weight: 800; margin-bottom: 20px; }
    .modal-input {
      width: 100%;
      padding: 12px 14px;
      background: rgba(255,255,255,0.06);
      border: 1px solid rgba(255,255,255,0.12);
      border-radius: 6px;
      color: var(--sp-white);
      font-size: 14px;
      font-family: var(--font);
      outline: none;
      transition: border-color 0.2s;
      margin-bottom: 12px;
    }
    .modal-input:focus { border-color: var(--sp-white); }
    .modal-btns { display: flex; gap: 10px; justify-content: flex-end; margin-top: 16px; }
    .btn-cancel {
      padding: 10px 22px;
      background: transparent;
      border: 1px solid rgba(255,255,255,0.2);
      border-radius: 50px;
      color: var(--sp-white);
      font-size: 13px; font-weight: 700; font-family: var(--font);
      cursor: pointer;
      transition: border-color 0.2s;
    }
    .btn-cancel:hover { border-color: var(--sp-white); }
    .btn-create {
      padding: 10px 28px;
      background: var(--sp-green);
      border: none;
      border-radius: 50px;
      color: var(--sp-black);
      font-size: 13px; font-weight: 700; font-family: var(--font);
      cursor: pointer;
      transition: background 0.2s, transform 0.1s;
    }
    .btn-create:hover { background: var(--sp-green-hover); transform: scale(1.02); }

    /* Playlist view */
    .playlist-header {
      padding: 48px 32px 32px;
      background: linear-gradient(180deg, rgba(29,185,84,0.3) 0%, transparent 100%);
      display: flex; align-items: flex-end; gap: 24px;
    }
    .playlist-cover {
      width: 200px; height: 200px;
      background: linear-gradient(135deg, #1a5c3a, var(--sp-green));
      border-radius: 4px;
      box-shadow: 0 12px 40px rgba(0,0,0,0.5);
      flex-shrink: 0;
      display: flex; align-items: center; justify-content: center;
      font-size: 72px;
    }
    .playlist-meta h1 { font-size: 48px; font-weight: 900; }
    .playlist-meta p { color: var(--sp-light); font-size: 14px; margin-top: 4px; }
    .playlist-controls { padding: 24px 32px 16px; display: flex; align-items: center; gap: 20px; }
    .big-play-btn {
      width: 54px; height: 54px;
      background: var(--sp-green);
      border-radius: 50%;
      border: none;
      color: var(--sp-black);
      cursor: pointer;
      display: flex; align-items: center; justify-content: center;
      box-shadow: 0 8px 20px rgba(29,185,84,0.4);
      transition: transform 0.15s, background 0.15s;
    }
    .big-play-btn:hover { transform: scale(1.06); background: var(--sp-green-hover); }
    .song-list { padding: 0 24px; }
    .song-list-header {
      display: grid;
      grid-template-columns: 40px 1fr 140px 60px;
      gap: 16px;
      padding: 8px 16px;
      border-bottom: 1px solid rgba(255,255,255,0.08);
      font-size: 12px;
      font-weight: 700;
      color: var(--sp-light);
      letter-spacing: 1px;
      text-transform: uppercase;
    }
    .song-row {
      display: grid;
      grid-template-columns: 40px 1fr 140px 60px;
      gap: 16px;
      padding: 8px 16px;
      border-radius: 6px;
      cursor: pointer;
      align-items: center;
      transition: background 0.15s;
    }
    .song-row:hover { background: rgba(255,255,255,0.07); }
    .song-row.playing { color: var(--sp-green); }
    .song-row-num { font-size: 14px; color: var(--sp-light); text-align: center; }
    .song-row.playing .song-row-num { color: var(--sp-green); }
    .song-row-info { display: flex; align-items: center; gap: 14px; min-width: 0; }
    .row-art { width: 40px; height: 40px; border-radius: 4px; object-fit: cover; flex-shrink: 0; font-size: 20px; display: flex; align-items: center; justify-content: center; background: var(--sp-card); }
    .row-art img { width: 100%; height: 100%; object-fit: cover; border-radius: 4px; }
    .row-title { font-size: 14px; font-weight: 600; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; }
    .row-artist { font-size: 12px; color: var(--sp-light); margin-top: 2px; }
    .row-album { font-size: 13px; color: var(--sp-light); white-space: nowrap; overflow: hidden; text-overflow: ellipsis; }
    .row-duration { font-size: 13px; color: var(--sp-light); text-align: right; }
    .add-song-btn {
      display: inline-flex; align-items: center; gap: 6px;
      padding: 8px 16px;
      background: transparent;
      border: 1px solid rgba(255,255,255,0.2);
      border-radius: 50px;
      color: var(--sp-light);
      font-size: 13px; font-weight: 600; font-family: var(--font);
      cursor: pointer;
      transition: all 0.2s;
    }
    .add-song-btn:hover { border-color: var(--sp-white); color: var(--sp-white); }

    /* ─── TOAST ─── */
    .toast {
      position: fixed;
      bottom: 110px;
      left: 50%;
      transform: translateX(-50%) translateY(20px);
      background: var(--sp-green);
      color: var(--sp-black);
      padding: 12px 24px;
      border-radius: 50px;
      font-size: 14px;
      font-weight: 700;
      box-shadow: 0 8px 24px rgba(0,0,0,0.4);
      z-index: 9999;
      animation: toastIn 0.3s ease forwards;
    }
    @keyframes toastIn {
      to { transform: translateX(-50%) translateY(0); opacity: 1; }
    }

    /* Search page */
    .search-grid { display: grid; grid-template-columns: repeat(auto-fill, minmax(180px, 1fr)); gap: 16px; }
    .genre-card {
      padding: 20px 16px;
      border-radius: 8px;
      cursor: pointer;
      position: relative;
      overflow: hidden;
      aspect-ratio: 1.2;
      transition: transform 0.15s;
    }
    .genre-card:hover { transform: scale(1.03); }
    .genre-card h3 { font-size: 18px; font-weight: 800; }
    .genre-card .big-icon { position: absolute; right: -8px; bottom: -12px; font-size: 72px; transform: rotate(15deg); opacity: 0.6; }

    /* Featured banner */
    .featured-banner {
      border-radius: 12px;
      padding: 40px;
      background: linear-gradient(135deg, #0f3460, #533483);
      position: relative;
      overflow: hidden;
      margin-bottom: 32px;
    }
    .featured-banner::before { content: ''; position: absolute; inset: 0; background: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 100 100'%3E%3Ccircle cx='80' cy='20' r='40' fill='rgba(255,255,255,0.03)'/%3E%3C/svg%3E") no-repeat center/cover; }
    .featured-banner h2 { font-size: 36px; font-weight: 900; }
    .featured-banner p { color: rgba(255,255,255,0.75); margin: 8px 0 20px; font-size: 15px; }

    /* pulse animation for playing indicator */
    @keyframes pulse { 0%,100% { opacity: 1; } 50% { opacity: 0.4; } }
    .playing-indicator { display: flex; align-items: flex-end; gap: 2px; height: 16px; }
    .playing-indicator span {
      width: 3px; background: var(--sp-green); border-radius: 1px;
      animation: barDance 0.8s ease-in-out infinite;
    }
    .playing-indicator span:nth-child(1) { height: 8px; animation-delay: 0s; }
    .playing-indicator span:nth-child(2) { height: 14px; animation-delay: 0.15s; }
    .playing-indicator span:nth-child(3) { height: 6px; animation-delay: 0.3s; }
    @keyframes barDance { 0%,100% { transform: scaleY(1); } 50% { transform: scaleY(0.4); } }

    .empty-state { text-align: center; padding: 60px 20px; color: var(--sp-light); }
    .empty-state .big-emoji { font-size: 64px; margin-bottom: 16px; }
    .empty-state h3 { font-size: 22px; color: var(--sp-white); font-weight: 800; margin-bottom: 8px; }
  </style>
</head>
<body>
<div id="root"></div>
<script type="text/babel">
const { useState, useEffect, useRef, useCallback } = React;

// ────────────────────────────────────────────────────────────────────────────
// CONSTANTS
// ────────────────────────────────────────────────────────────────────────────
const CLIENT_ID = '852e3830a5744bb5ac6bf43be434ead9'; // ← Replace with your Spotify Client ID
const REDIRECT_URI = window.location.href.split('?')[0].split('#')[0];
const SCOPES = 'streaming user-read-email user-read-private user-library-modify playlist-modify-public playlist-modify-private user-read-playback-state user-modify-playback-state';

const MOODS = [
  { id: 'happy',    label: 'Happy',    emoji: '😄', desc: 'Upbeat & joyful vibes', color: 'mood-happy',    query: 'happy upbeat pop',          seeds: '4NHQUkpP4gvEIanHWuJC6p,5CQ30WqJwcep0pYcV4AMNc' },
  { id: 'sad',      label: 'Sad',      emoji: '😢', desc: 'Melancholic feels',     color: 'mood-sad',      query: 'sad emotional heartbreak',   seeds: '7M1FPw29m5FbeFDcd45vs2,3TVXtAsR1Inumwj472S9r4' },
  { id: 'chill',    label: 'Chill',    emoji: '😎', desc: 'Relaxed & laid back',   color: 'mood-chill',    query: 'chill lofi relaxed ambient',  seeds: '69GGBxA162lTqCwzJG5jLp,4tZwfgrHOc3mvqYlEYSvVi' },
  { id: 'party',    label: 'Party',    emoji: '🎉', desc: 'High energy bangers',   color: 'mood-party',    query: 'party dance edm club',        seeds: '0du5cEVh5yTK9QJze8zA0C,3fMbdgg4jU18AjLCKBhRSm' },
  { id: 'romantic', label: 'Romantic', emoji: '💕', desc: 'Love & romance',        color: 'mood-romantic', query: 'romantic love ballad',        seeds: '4PXpKO9h9muVqVrGUKhRuX,7Ln80lUS6He07XvHI8qqHH' },
  { id: 'angry',    label: 'Angry',    emoji: '😤', desc: 'Raw & intense energy',  color: 'mood-angry',    query: 'rock metal intense angry',    seeds: '2ye2Wgw4gimLv2eAKyk1NB,699OTQXzgjhIYAHMy9RyPD' },
];

const DEMO_TRACKS = {
  happy:    [
    { id:'h1', name:'Blinding Lights',      artist:'The Weeknd',    album:'After Hours',     duration:'3:22', emoji:'🌟' },
    { id:'h2', name:'Happy',                artist:'Pharrell Williams', album:'Despicable Me 2', duration:'3:53', emoji:'😊' },
    { id:'h3', name:'Can\'t Stop the Feeling', artist:'Justin Timberlake', album:'Trolls',  duration:'3:56', emoji:'🕺' },
    { id:'h4', name:'Good as Hell',         artist:'Lizzo',         album:'Cuz I Love You',  duration:'2:39', emoji:'💪' },
    { id:'h5', name:'Shake It Off',         artist:'Taylor Swift',  album:'1989',            duration:'3:39', emoji:'✨' },
    { id:'h6', name:'Levitating',           artist:'Dua Lipa',      album:'Future Nostalgia',duration:'3:23', emoji:'🚀' },
  ],
  sad: [
    { id:'s1', name:'Someone Like You',     artist:'Adele',         album:'21',              duration:'4:45', emoji:'💧' },
    { id:'s2', name:'The Night We Met',     artist:'Lord Huron',    album:'Strange Trails',  duration:'3:28', emoji:'🌑' },
    { id:'s3', name:'Fix You',              artist:'Coldplay',      album:'X&Y',             duration:'4:55', emoji:'🕯️' },
    { id:'s4', name:'Let Her Go',           artist:'Passenger',     album:'All the Little Lights', duration:'4:14', emoji:'🍂' },
    { id:'s5', name:'Skinny Love',          artist:'Bon Iver',      album:'For Emma, Forever Ago', duration:'3:58', emoji:'❄️' },
    { id:'s6', name:'Hurt',                 artist:'Johnny Cash',   album:'American IV',     duration:'3:38', emoji:'🥀' },
  ],
  chill: [
    { id:'c1', name:'Sunset Lover',         artist:'Petit Biscuit', album:'Presence',        duration:'4:00', emoji:'🌅' },
    { id:'c2', name:'Breathe',              artist:'Télépopmusik',  album:'Genetic World',   duration:'4:27', emoji:'🌿' },
    { id:'c3', name:'Outro',                artist:'M83',           album:'Hurry Up, We\'re Dreaming', duration:'9:26', emoji:'🌙' },
    { id:'c4', name:'Electric Feel',        artist:'MGMT',          album:'Oracular Spectacular', duration:'3:49', emoji:'⚡' },
    { id:'c5', name:'Lost in Japan',        artist:'Shawn Mendes',  album:'Shawn Mendes',    duration:'3:04', emoji:'🌸' },
    { id:'c6', name:'Banana Pancakes',      artist:'Jack Johnson',  album:'In Between Dreams', duration:'3:13', emoji:'🍌' },
  ],
  party: [
    { id:'p1', name:'Blurred Lines',        artist:'Robin Thicke',  album:'Blurred Lines',   duration:'4:22', emoji:'🎊' },
    { id:'p2', name:'Don\'t Stop the Music',artist:'Rihanna',       album:'Good Girl Gone Bad', duration:'4:27', emoji:'🎵' },
    { id:'p3', name:'Get Lucky',            artist:'Daft Punk',     album:'Random Access Memories', duration:'4:09', emoji:'🎸' },
    { id:'p4', name:'Uptown Funk',          artist:'Mark Ronson ft. Bruno Mars', album:'Uptown Special', duration:'4:30', emoji:'🕺' },
    { id:'p5', name:'Dynamite',             artist:'BTS',           album:'BE',              duration:'3:19', emoji:'💥' },
    { id:'p6', name:'Boom Boom',            artist:'RedOne',        album:'Boom',            duration:'3:28', emoji:'🔥' },
  ],
  romantic: [
    { id:'r1', name:'Perfect',              artist:'Ed Sheeran',    album:'÷',               duration:'4:23', emoji:'💖' },
    { id:'r2', name:'All of Me',            artist:'John Legend',   album:'Love in the Future', duration:'4:29', emoji:'💝' },
    { id:'r3', name:'A Thousand Years',     artist:'Christina Perri', album:'Twilight Saga', duration:'4:45', emoji:'🌹' },
    { id:'r4', name:'Make You Feel My Love',artist:'Adele',         album:'19',              duration:'3:31', emoji:'💌' },
    { id:'r5', name:'Can\'t Help Falling in Love', artist:'Elvis Presley', album:'Blue Hawaii', duration:'3:00', emoji:'🎵' },
    { id:'r6', name:'At Last',              artist:'Etta James',    album:'At Last!',        duration:'2:59', emoji:'🌙' },
  ],
  angry: [
    { id:'a1', name:'Break Stuff',          artist:'Limp Bizkit',   album:'Significant Other', duration:'2:46', emoji:'💢' },
    { id:'a2', name:'Killing in the Name',  artist:'Rage Against the Machine', album:'RATM', duration:'5:13', emoji:'✊' },
    { id:'a3', name:'Du Hast',              artist:'Rammstein',     album:'Sehnsucht',       duration:'3:55', emoji:'⚡' },
    { id:'a4', name:'Freak on a Leash',     artist:'Korn',          album:'Follow the Leader', duration:'4:16', emoji:'🤘' },
    { id:'a5', name:'Down with the Sickness',artist:'Disturbed',    album:'The Sickness',    duration:'4:37', emoji:'😠' },
    { id:'a6', name:'Before I Forget',      artist:'Slipknot',      album:'Vol 3',           duration:'4:39', emoji:'🎸' },
  ],
};

// ────────────────────────────────────────────────────────────────────────────
// Spotify Auth helpers
// ────────────────────────────────────────────────────────────────────────────
function getSpotifyAuthUrl() {
  const params = new URLSearchParams({
    client_id: CLIENT_ID,
    response_type: 'token',
    redirect_uri: REDIRECT_URI,
    scope: SCOPES,
    show_dialog: 'true',
  });
  return `https://accounts.spotify.com/authorize?${params}`;
}

function getTokenFromHash() {
  const hash = window.location.hash.substring(1);
  if (!hash) return null;
  const params = new URLSearchParams(hash);
  return params.get('access_token');
}

async function spotifyFetch(endpoint, token) {
  try {
    const res = await fetch(`https://api.spotify.com/v1${endpoint}`, {
      headers: { Authorization: `Bearer ${token}` }
    });
    if (!res.ok) return null;
    return res.json();
  } catch { return null; }
}

async function searchTracks(query, token, limit = 6) {
  const data = await spotifyFetch(`/search?q=${encodeURIComponent(query)}&type=track&limit=${limit}`, token);
  return data?.tracks?.items || [];
}

// ────────────────────────────────────────────────────────────────────────────
// ICONS
// ────────────────────────────────────────────────────────────────────────────
const SpotifyIcon = () => (
  <svg viewBox="0 0 24 24" fill="currentColor" style={{color:'#1DB954'}}>
    <path d="M12 0C5.4 0 0 5.4 0 12s5.4 12 12 12 12-5.4 12-12S18.66 0 12 0zm5.521 17.34c-.24.359-.66.48-1.021.24-2.82-1.74-6.36-2.101-10.561-1.141-.418.122-.779-.179-.899-.539-.12-.421.18-.78.54-.9 4.56-1.021 8.52-.6 11.64 1.32.42.18.479.659.301 1.02zm1.44-3.3c-.301.42-.841.6-1.262.3-3.239-1.98-8.159-2.58-11.939-1.38-.479.12-1.02-.12-1.14-.6-.12-.48.12-1.021.6-1.141C9.6 9.9 15 10.561 18.72 12.84c.361.181.54.78.241 1.2zm.12-3.36C15.24 8.4 8.82 8.16 5.16 9.301c-.6.179-1.2-.181-1.38-.721-.18-.601.18-1.2.72-1.381 4.26-1.26 11.28-1.02 15.721 1.621.539.3.719 1.02.419 1.56-.299.421-1.02.599-1.559.3z"/>
  </svg>
);

const HomeIcon = () => <svg className="nav-icon" viewBox="0 0 24 24" fill="currentColor"><path d="M10 20v-6h4v6h5v-8h3L12 3 2 12h3v8z"/></svg>;
const SearchIcon = () => <svg className="nav-icon" viewBox="0 0 24 24" fill="currentColor"><path d="M15.5 14h-.79l-.28-.27C15.41 12.59 16 11.11 16 9.5 16 5.91 13.09 3 9.5 3S3 5.91 3 9.5 5.91 16 9.5 16c1.61 0 3.09-.59 4.23-1.57l.27.28v.79l5 4.99L20.49 19l-4.99-5zm-6 0C7.01 14 5 11.99 5 9.5S7.01 5 9.5 5 14 7.01 14 9.5 11.99 14 9.5 14z"/></svg>;
const LibraryIcon = () => <svg className="nav-icon" viewBox="0 0 24 24" fill="currentColor"><path d="M20 2H8c-1.1 0-2 .9-2 2v12c0 1.1.9 2 2 2h12c1.1 0 2-.9 2-2V4c0-1.1-.9-2-2-2zm-2 5h-3v5.5a2.5 2.5 0 0 1-5 0 2.5 2.5 0 0 1 2.5-2.5c.57 0 1.08.19 1.5.5V5h4v2zM4 6H2v14c0 1.1.9 2 2 2h14v-2H4V6z"/></svg>;
const PlusIcon = () => <svg width="16" height="16" viewBox="0 0 24 24" fill="currentColor"><path d="M19 13h-6v6h-2v-6H5v-2h6V5h2v6h6v2z"/></svg>;
const PlayIcon = ({size=18}) => <svg width={size} height={size} viewBox="0 0 24 24" fill="currentColor"><path d="M8 5v14l11-7z"/></svg>;
const PauseIcon = ({size=18}) => <svg width={size} height={size} viewBox="0 0 24 24" fill="currentColor"><path d="M6 19h4V5H6v14zm8-14v14h4V5h-4z"/></svg>;
const SkipNextIcon = () => <svg width="20" height="20" viewBox="0 0 24 24" fill="currentColor"><path d="M6 18l8.5-6L6 6v12zM16 6v12h2V6h-2z"/></svg>;
const SkipPrevIcon = () => <svg width="20" height="20" viewBox="0 0 24 24" fill="currentColor"><path d="M6 6h2v12H6zm3.5 6 8.5 6V6z"/></svg>;
const ShuffleIcon = () => <svg width="18" height="18" viewBox="0 0 24 24" fill="currentColor"><path d="M10.59 9.17L5.41 4 4 5.41l5.17 5.17 1.42-1.41zM14.5 4l2.04 2.04L4 18.59 5.41 20 17.96 7.46 20 9.5V4h-5.5zm.33 9.41-1.41 1.41 3.13 3.13L14.5 20H20v-5.5l-2.04 2.04-3.13-3.13z"/></svg>;
const RepeatIcon = () => <svg width="18" height="18" viewBox="0 0 24 24" fill="currentColor"><path d="M7 7h10v3l4-4-4-4v3H5v6h2V7zm10 10H7v-3l-4 4 4 4v-3h12v-6h-2v4z"/></svg>;
const HeartIcon = ({filled}) => <svg width="16" height="16" viewBox="0 0 24 24" fill={filled?"currentColor":"none"} stroke="currentColor" strokeWidth="2"><path d="M20.84 4.61a5.5 5.5 0 0 0-7.78 0L12 5.67l-1.06-1.06a5.5 5.5 0 0 0-7.78 7.78l1.06 1.06L12 21.23l7.78-7.78 1.06-1.06a5.5 5.5 0 0 0 0-7.78z"/></svg>;
const VolumeIcon = () => <svg width="16" height="16" viewBox="0 0 24 24" fill="currentColor"><path d="M3 9v6h4l5 5V4L7 9H3zm13.5 3c0-1.77-1.02-3.29-2.5-4.03v8.05c1.48-.73 2.5-2.25 2.5-4.02zM14 3.23v2.06c2.89.86 5 3.54 5 6.71s-2.11 5.85-5 6.71v2.06c4.01-.91 7-4.49 7-8.77s-2.99-7.86-7-8.77z"/></svg>;
const MoodIcon = () => <svg className="nav-icon" viewBox="0 0 24 24" fill="currentColor"><path d="M11.99 2C6.47 2 2 6.48 2 12s4.47 10 9.99 10C17.52 22 22 17.52 22 12S17.52 2 11.99 2zM12 20c-4.42 0-8-3.58-8-8s3.58-8 8-8 8 3.58 8 8-3.58 8-8 8zm3.5-9c.83 0 1.5-.67 1.5-1.5S16.33 8 15.5 8 14 8.67 14 9.5s.67 1.5 1.5 1.5zm-7 0c.83 0 1.5-.67 1.5-1.5S9.33 8 8.5 8 7 8.67 7 9.5 7.67 11 8.5 11zm3.5 6.5c2.33 0 4.31-1.46 5.11-3.5H6.89c.8 2.04 2.78 3.5 5.11 3.5z"/></svg>;

// ────────────────────────────────────────────────────────────────────────────
// TOAST
// ────────────────────────────────────────────────────────────────────────────
function Toast({ msg, onDone }) {
  useEffect(() => { const t = setTimeout(onDone, 2400); return () => clearTimeout(t); }, []);
  return <div className="toast">{msg}</div>;
}

// ────────────────────────────────────────────────────────────────────────────
// LOGIN PAGE
// ────────────────────────────────────────────────────────────────────────────
function LoginPage({ onDemoLogin }) {
  const [mode, setMode] = useState('login'); // login | signup
  const [form, setForm] = useState({ email:'', password:'', name:'' });

  const handleSpotify = () => {
    if (CLIENT_ID === 'YOUR_SPOTIFY_CLIENT_ID') {
      alert('🎵 Moodify Demo Mode\n\nTo connect real Spotify:\n1. Create app at developer.spotify.com\n2. Replace CLIENT_ID at top of code\n3. Add redirect URI\n\nFor now, enjoy the demo!');
      onDemoLogin({ name: 'Demo User', email: 'demo@moodify.app' });
    } else {
      window.location.href = getSpotifyAuthUrl();
    }
  };

  const handleSubmit = () => {
    if (!form.email || !form.password) return;
    onDemoLogin({ name: form.name || form.email.split('@')[0], email: form.email });
  };

  return (
    <div className="login-page">
      <div className="login-orbs">
        <div className="orb orb1" /><div className="orb orb2" /><div className="orb orb3" />
      </div>
      <div className="login-box">
        <div className="login-logo">
          <SpotifyIcon />
          <h1>Moodify</h1>
          <p>Your emotion-powered music universe</p>
        </div>

        <button className="spotify-btn-outline" onClick={handleSpotify}>
          <SpotifyIcon /> Continue with Spotify
        </button>

        <div className="login-divider">or</div>

        {mode === 'signup' && (
          <div className="login-input-group">
            <label>Your Name</label>
            <input type="text" placeholder="What should we call you?" value={form.name}
              onChange={e => setForm({...form, name: e.target.value})} />
          </div>
        )}

        <div className="login-input-group">
          <label>Email address</label>
          <input type="email" placeholder="name@example.com" value={form.email}
            onChange={e => setForm({...form, email: e.target.value})}
            onKeyDown={e => e.key === 'Enter' && handleSubmit()} />
        </div>
        <div className="login-input-group">
          <label>Password</label>
          <input type="password" placeholder="••••••••" value={form.password}
            onChange={e => setForm({...form, password: e.target.value})}
            onKeyDown={e => e.key === 'Enter' && handleSubmit()} />
        </div>

        <button className="btn-spotify" onClick={handleSubmit}>
          {mode === 'login' ? 'Log In' : 'Create Account'}
        </button>

        <div className="login-toggle">
          {mode === 'login'
            ? <>Don't have an account? <a onClick={() => setMode('signup')}>Sign up free</a></>
            : <>Already have an account? <a onClick={() => setMode('login')}>Log in</a></>}
        </div>
      </div>
    </div>
  );
}

// ────────────────────────────────────────────────────────────────────────────
// SIDEBAR
// ────────────────────────────────────────────────────────────────────────────
function Sidebar({ page, setPage, playlists, onCreatePlaylist, currentPlaylist, setCurrentPlaylist }) {
  return (
    <nav className="sidebar">
      <div className="sidebar-logo">
        <SpotifyIcon />
        <span>Moodify</span>
      </div>

      <div className="nav-section">
        {[
          { id:'home', label:'Home', icon:<HomeIcon /> },
          { id:'search', label:'Search', icon:<SearchIcon /> },
          { id:'moods', label:'Moods', icon:<MoodIcon /> },
        ].map(item => (
          <div key={item.id} className={`nav-item ${page===item.id?'active':''}`} onClick={() => setPage(item.id)}>
            {item.icon} {item.label}
          </div>
        ))}
      </div>

      <div className="sidebar-divider" />

      <div className="nav-section">
        <div className={`nav-item ${page==='library'?'active':''}`} onClick={() => setPage('library')}>
          <LibraryIcon /> Your Library
        </div>
        <div className="nav-item" onClick={onCreatePlaylist} style={{color:'var(--sp-green)'}}>
          <PlusIcon /> Create Playlist
        </div>
      </div>

      <div className="sidebar-divider" />

      <div className="playlist-list">
        {playlists.map(pl => (
          <div key={pl.id}
            className={`playlist-item ${currentPlaylist?.id===pl.id&&page==='playlist'?'active':''}`}
            onClick={() => { setCurrentPlaylist(pl); setPage('playlist'); }}>
            {pl.name}
          </div>
        ))}
      </div>
    </nav>
  );
}

// ────────────────────────────────────────────────────────────────────────────
// SONG CARD
// ────────────────────────────────────────────────────────────────────────────
function SongCard({ track, onPlay, isPlaying }) {
  return (
    <div className="song-card" onClick={() => onPlay(track)}>
      <div className="song-art">
        {track.album_art
          ? <img src={track.album_art} alt={track.name} onError={e => { e.target.style.display='none'; }} />
          : <div className="song-art-placeholder">{track.emoji || '🎵'}</div>}
        <button className="play-btn-overlay">
          {isPlaying ? <PauseIcon /> : <PlayIcon />}
        </button>
      </div>
      <h4>{track.name}</h4>
      <p>{track.artist}</p>
    </div>
  );
}

// ────────────────────────────────────────────────────────────────────────────
// HOME PAGE
// ────────────────────────────────────────────────────────────────────────────
function HomePage({ onPlay, currentTrack, playlists, onAddToPlaylist, token }) {
  const [featured, setFeatured] = useState(DEMO_TRACKS.happy.slice(0,6));

  return (
    <div className="main-body">
      <div className="featured-banner">
        <h2>🎵 Welcome to Moodify</h2>
        <p>Music that matches how you feel. Pick a mood and let the vibes flow.</p>
        <button className="btn-spotify" style={{width:'auto',padding:'12px 32px'}}
          onClick={() => onPlay(featured[0])}>
          Start Listening
        </button>
      </div>

      <div className="section-header">
        <h3>🔥 Trending Right Now</h3>
        <a>See all</a>
      </div>
      <div className="song-grid">
        {featured.map(t => (
          <SongCard key={t.id} track={t} onPlay={onPlay} isPlaying={currentTrack?.id===t.id} />
        ))}
      </div>

      <div className="section-header" style={{marginTop:32}}>
        <h3>💚 Mood Picks</h3>
        <a>See all</a>
      </div>
      <div className="song-grid">
        {DEMO_TRACKS.chill.slice(0,6).map(t => (
          <SongCard key={t.id} track={t} onPlay={onPlay} isPlaying={currentTrack?.id===t.id} />
        ))}
      </div>
    </div>
  );
}

// ────────────────────────────────────────────────────────────────────────────
// MOODS PAGE
// ────────────────────────────────────────────────────────────────────────────
function MoodsPage({ onPlay, currentTrack, token, onAddToPlaylist }) {
  const [selectedMood, setSelectedMood] = useState(null);
  const [tracks, setTracks] = useState([]);
  const [loading, setLoading] = useState(false);

  const selectMood = async (mood) => {
    setSelectedMood(mood);
    setLoading(true);
    if (token && token !== 'demo') {
      const results = await searchTracks(mood.query, token, 12);
      if (results.length) {
        setTracks(results.map(t => ({
          id: t.id,
          name: t.name,
          artist: t.artists.map(a=>a.name).join(', '),
          album: t.album.name,
          duration: `${Math.floor(t.duration_ms/60000)}:${String(Math.floor((t.duration_ms%60000)/1000)).padStart(2,'0')}`,
          album_art: t.album.images[0]?.url,
          uri: t.uri,
          emoji: mood.emoji,
        })));
        setLoading(false);
        return;
      }
    }
    // Demo fallback
    setTracks(DEMO_TRACKS[mood.id] || []);
    setLoading(false);
  };

  return (
    <div className="main-body">
      <div className="mood-hero">
        <h2>How are you feeling?</h2>
        <p>Choose your mood and we'll curate the perfect soundtrack for your moment.</p>
        <div className="mood-grid">
          {MOODS.map(m => (
            <div key={m.id} className={`mood-card ${m.color} ${selectedMood?.id===m.id?'active':''}`}
              onClick={() => selectMood(m)}>
              <span className="mood-emoji">{m.emoji}</span>
              <div className="mood-card-info">
                <h3>{m.label}</h3>
                <p>{m.desc}</p>
              </div>
            </div>
          ))}
        </div>
      </div>

      {selectedMood && (
        <>
          <div className="section-header">
            <h3>{selectedMood.emoji} {selectedMood.label} Playlist</h3>
            <a onClick={() => setSelectedMood(null)}>Clear</a>
          </div>
          {loading ? (
            <div className="empty-state"><p>🎵 Loading tracks...</p></div>
          ) : (
            <div className="song-grid">
              {tracks.map(t => (
                <SongCard key={t.id} track={t} onPlay={onPlay} isPlaying={currentTrack?.id===t.id} />
              ))}
            </div>
          )}
        </>
      )}

      {!selectedMood && (
        <div className="empty-state">
          <div className="big-emoji">🎭</div>
          <h3>Pick your mood above</h3>
          <p>We'll find the perfect songs to match how you feel</p>
        </div>
      )}
    </div>
  );
}

// ────────────────────────────────────────────────────────────────────────────
// SEARCH PAGE
// ────────────────────────────────────────────────────────────────────────────
function SearchPage({ onPlay, currentTrack, token }) {
  const [query, setQuery] = useState('');
  const [results, setResults] = useState([]);
  const [searching, setSearching] = useState(false);
  const timerRef = useRef(null);

  const doSearch = useCallback(async (q) => {
    if (!q.trim()) { setResults([]); return; }
    setSearching(true);
    if (token && token !== 'demo') {
      const items = await searchTracks(q, token, 12);
      if (items.length) {
        setResults(items.map(t => ({
          id: t.id, name: t.name,
          artist: t.artists.map(a=>a.name).join(', '),
          album: t.album.name,
          duration: `${Math.floor(t.duration_ms/60000)}:${String(Math.floor((t.duration_ms%60000)/1000)).padStart(2,'0')}`,
          album_art: t.album.images[0]?.url, uri: t.uri, emoji:'🎵',
        })));
        setSearching(false); return;
      }
    }
    // Demo search
    const all = Object.values(DEMO_TRACKS).flat();
    const lq = q.toLowerCase();
    setResults(all.filter(t => t.name.toLowerCase().includes(lq) || t.artist.toLowerCase().includes(lq)));
    setSearching(false);
  }, [token]);

  useEffect(() => {
    clearTimeout(timerRef.current);
    timerRef.current = setTimeout(() => doSearch(query), 400);
  }, [query, doSearch]);

  const genres = [
    {n:'Pop',c:'#1a6e8c',e:'🎤'},{n:'Hip-Hop',c:'#6e1a1a',e:'🎤'},
    {n:'Rock',c:'#3a1a6e',e:'🎸'},{n:'Electronic',c:'#1a6e3a',e:'💿'},
    {n:'Jazz',c:'#6e4a1a',e:'🎺'},{n:'Classical',c:'#4a6e1a',e:'🎻'},
    {n:'R&B',c:'#6e1a5c',e:'🎵'},{n:'Country',c:'#6e5c1a',e:'🤠'},
  ];

  return (
    <div className="main-body">
      <h2 style={{fontSize:28,fontWeight:900,margin:'8px 0 20px'}}>Search</h2>
      <input className="modal-input" style={{fontSize:16,padding:'14px 18px',borderRadius:50,marginBottom:24}}
        placeholder="What do you want to listen to?"
        value={query} onChange={e => setQuery(e.target.value)} />

      {query ? (
        <>
          <div className="section-header"><h3>Results</h3></div>
          {searching ? <p style={{color:'var(--sp-light)'}}>Searching...</p> :
            results.length ? (
              <div className="song-grid">
                {results.map(t => <SongCard key={t.id} track={t} onPlay={onPlay} isPlaying={currentTrack?.id===t.id} />)}
              </div>
            ) : <p style={{color:'var(--sp-light)'}}>No results found</p>}
        </>
      ) : (
        <>
          <div className="section-header"><h3>Browse Categories</h3></div>
          <div className="search-grid">
            {genres.map(g => (
              <div key={g.n} className="genre-card" style={{background:g.c}}
                onClick={() => setQuery(g.n)}>
                <h3>{g.n}</h3>
                <span className="big-icon">{g.e}</span>
              </div>
            ))}
          </div>
        </>
      )}
    </div>
  );
}

// ────────────────────────────────────────────────────────────────────────────
// LIBRARY PAGE
// ────────────────────────────────────────────────────────────────────────────
function LibraryPage({ playlists, setPage, setCurrentPlaylist, onCreatePlaylist }) {
  return (
    <div className="main-body">
      <div style={{display:'flex',alignItems:'center',justifyContent:'space-between',padding:'8px 0 24px'}}>
        <h2 style={{fontSize:28,fontWeight:900}}>Your Library</h2>
        <button className="btn-create" onClick={onCreatePlaylist} style={{display:'flex',alignItems:'center',gap:6}}>
          <PlusIcon /> New Playlist
        </button>
      </div>
      {playlists.length === 0 ? (
        <div className="empty-state">
          <div className="big-emoji">📚</div>
          <h3>No playlists yet</h3>
          <p>Create your first playlist and fill it with your favorite songs</p>
          <button className="btn-create" style={{marginTop:20}} onClick={onCreatePlaylist}>Create playlist</button>
        </div>
      ) : (
        <div className="song-grid">
          {playlists.map(pl => (
            <div key={pl.id} className="song-card" onClick={() => { setCurrentPlaylist(pl); setPage('playlist'); }}>
              <div className="song-art">
                <div className="song-art-placeholder" style={{background:'linear-gradient(135deg,#1a5c3a,#1DB954)'}}>
                  {pl.emoji || '🎵'}
                </div>
              </div>
              <h4>{pl.name}</h4>
              <p>{pl.tracks.length} songs</p>
            </div>
          ))}
        </div>
      )}
    </div>
  );
}

// ────────────────────────────────────────────────────────────────────────────
// PLAYLIST VIEW
// ────────────────────────────────────────────────────────────────────────────
function PlaylistView({ playlist, onPlay, currentTrack, onRemoveTrack }) {
  const totalDur = playlist.tracks.reduce((acc, t) => {
    const [m,s] = (t.duration||'3:30').split(':').map(Number);
    return acc + m*60 + s;
  }, 0);
  const fmtDur = `${Math.floor(totalDur/60)} min ${totalDur%60} sec`;

  return (
    <>
      <div className="playlist-header">
        <div className="playlist-cover">{playlist.emoji || '🎵'}</div>
        <div className="playlist-meta">
          <p style={{fontSize:12,fontWeight:700,letterSpacing:1,textTransform:'uppercase'}}>Playlist</p>
          <h1 style={{fontSize: playlist.name.length > 14 ? 32 : 48}}>{playlist.name}</h1>
          <p style={{marginTop:8}}>{playlist.tracks.length} songs · {fmtDur}</p>
        </div>
      </div>

      <div className="playlist-controls">
        <button className="big-play-btn" onClick={() => playlist.tracks[0] && onPlay(playlist.tracks[0])}>
          <PlayIcon size={24} />
        </button>
        <button className="add-song-btn" style={{color:'var(--sp-light)'}}>
          ♥ Follow
        </button>
      </div>

      <div className="song-list">
        {playlist.tracks.length === 0 ? (
          <div className="empty-state">
            <div className="big-emoji">🎶</div>
            <h3>This playlist is empty</h3>
            <p>Go to Moods or Search to find songs to add</p>
          </div>
        ) : (
          <>
            <div className="song-list-header">
              <span>#</span><span>Title</span><span>Album</span><span>⏱</span>
            </div>
            {playlist.tracks.map((t, i) => (
              <div key={t.id+i} className={`song-row ${currentTrack?.id===t.id?'playing':''}`}
                onClick={() => onPlay(t)}>
                <div className="song-row-num">
                  {currentTrack?.id===t.id
                    ? <div className="playing-indicator"><span/><span/><span/></div>
                    : i+1}
                </div>
                <div className="song-row-info">
                  <div className="row-art">
                    {t.album_art ? <img src={t.album_art} alt="" /> : (t.emoji||'🎵')}
                  </div>
                  <div>
                    <div className="row-title">{t.name}</div>
                    <div className="row-artist">{t.artist}</div>
                  </div>
                </div>
                <div className="row-album">{t.album}</div>
                <div className="row-duration">{t.duration}</div>
              </div>
            ))}
          </>
        )}
      </div>
    </>
  );
}

// ────────────────────────────────────────────────────────────────────────────
// CREATE PLAYLIST MODAL
// ────────────────────────────────────────────────────────────────────────────
function CreatePlaylistModal({ onCreate, onClose }) {
  const [name, setName] = useState('');
  const [desc, setDesc] = useState('');
  const emojis = ['🎵','🎸','🎺','🎻','🥁','🎹','🎤','🎧','🎼','🎶'];
  const [emoji, setEmoji] = useState('🎵');

  return (
    <div className="modal-overlay" onClick={e => e.target===e.currentTarget&&onClose()}>
      <div className="modal-box">
        <h2>Create Playlist</h2>
        <div style={{display:'flex',gap:8,flexWrap:'wrap',marginBottom:16}}>
          {emojis.map(e => (
            <button key={e} onClick={() => setEmoji(e)}
              style={{background:emoji===e?'var(--sp-green)':'rgba(255,255,255,0.1)',border:'none',borderRadius:8,padding:'6px 10px',fontSize:20,cursor:'pointer',transition:'all 0.15s'}}>
              {e}
            </button>
          ))}
        </div>
        <input className="modal-input" placeholder="Playlist name" value={name}
          onChange={e => setName(e.target.value)}
          onKeyDown={e => e.key==='Enter'&&name.trim()&&onCreate(name.trim(),desc,emoji)} />
        <input className="modal-input" placeholder="Add a description (optional)" value={desc}
          onChange={e => setDesc(e.target.value)} />
        <div className="modal-btns">
          <button className="btn-cancel" onClick={onClose}>Cancel</button>
          <button className="btn-create" disabled={!name.trim()}
            onClick={() => onCreate(name.trim(), desc, emoji)}>Create</button>
        </div>
      </div>
    </div>
  );
}

// ────────────────────────────────────────────────────────────────────────────
// ADD TO PLAYLIST MODAL
// ────────────────────────────────────────────────────────────────────────────
function AddToPlaylistModal({ playlists, track, onAdd, onClose }) {
  return (
    <div className="modal-overlay" onClick={e => e.target===e.currentTarget&&onClose()}>
      <div className="modal-box">
        <h2>Add to Playlist</h2>
        <p style={{color:'var(--sp-light)',marginBottom:20,fontSize:14}}>"{track.name}" by {track.artist}</p>
        {playlists.length === 0 ? (
          <p style={{color:'var(--sp-light)',fontSize:14}}>No playlists yet. Create one first!</p>
        ) : (
          <div style={{display:'flex',flexDirection:'column',gap:8,maxHeight:300,overflowY:'auto'}}>
            {playlists.map(pl => (
              <button key={pl.id} onClick={() => onAdd(pl.id)}
                style={{display:'flex',alignItems:'center',gap:12,padding:'12px 16px',background:'rgba(255,255,255,0.05)',border:'1px solid rgba(255,255,255,0.08)',borderRadius:8,cursor:'pointer',color:'var(--sp-white)',font:'600 14px var(--font)',transition:'background 0.15s',textAlign:'left'}}>
                <span style={{fontSize:24}}>{pl.emoji||'🎵'}</span>
                <span style={{flex:1}}>{pl.name}</span>
                <span style={{color:'var(--sp-light)',fontSize:12}}>{pl.tracks.length} songs</span>
              </button>
            ))}
          </div>
        )}
        <div className="modal-btns"><button className="btn-cancel" onClick={onClose}>Cancel</button></div>
      </div>
    </div>
  );
}

// ────────────────────────────────────────────────────────────────────────────
// NOW PLAYING BAR
// ────────────────────────────────────────────────────────────────────────────
function NowPlayingBar({ track, isPlaying, togglePlay, skipNext, skipPrev, shuffle, repeat, toggleShuffle, toggleRepeat, liked, toggleLike, progress, volume, setVolume, onAddToPlaylist }) {
  return (
    <div className="now-playing-bar">
      {/* Left: Track Info */}
      <div className="np-track">
        {track ? (
          <>
            <div className="np-art">
              {track.album_art ? <img src={track.album_art} alt="" /> : (track.emoji||'🎵')}
            </div>
            <div className="np-info">
              <h4>{track.name}</h4>
              <p>{track.artist}</p>
            </div>
            <button className={`np-like ${liked?'liked':''}`} onClick={toggleLike}><HeartIcon filled={liked}/></button>
          </>
        ) : (
          <div style={{color:'var(--sp-light)',fontSize:13}}>No track playing</div>
        )}
      </div>

      {/* Center: Controls */}
      <div className="np-controls">
        <div className="np-btns">
          <button className={`ctrl-btn ${shuffle?'active':''}`} onClick={toggleShuffle}><ShuffleIcon/></button>
          <button className="ctrl-btn" onClick={skipPrev}><SkipPrevIcon/></button>
          <button className="play-pause-btn" onClick={togglePlay}>
            {isPlaying ? <PauseIcon size={18}/> : <PlayIcon size={18}/>}
          </button>
          <button className="ctrl-btn" onClick={skipNext}><SkipNextIcon/></button>
          <button className={`ctrl-btn ${repeat?'active':''}`} onClick={toggleRepeat}><RepeatIcon/></button>
        </div>
        <div className="progress-bar-row">
          <span className="time-label">{Math.floor(progress/60)}:{String(progress%60).padStart(2,'0')}</span>
          <div className="progress-track">
            <div className="progress-fill" style={{width:`${Math.min(progress/240*100,100)}%`}} />
          </div>
          <span className="time-label">4:00</span>
        </div>
      </div>

      {/* Right: Volume */}
      <div className="np-extra">
        {track && (
          <button className="add-song-btn" onClick={() => onAddToPlaylist(track)}
            style={{fontSize:11,padding:'4px 12px'}}>
            + Playlist
          </button>
        )}
        <div className="volume-row">
          <button className="ctrl-btn"><VolumeIcon/></button>
          <div className="volume-track" onClick={e => {
            const rect = e.currentTarget.getBoundingClientRect();
            setVolume(Math.max(0,Math.min(1,(e.clientX-rect.left)/rect.width)));
          }}>
            <div className="volume-fill" style={{width:`${volume*100}%`}} />
          </div>
        </div>
      </div>
    </div>
  );
}

// ────────────────────────────────────────────────────────────────────────────
// MAIN APP
// ────────────────────────────────────────────────────────────────────────────
function App() {
  const [user, setUser] = useState(null);
  const [token, setToken] = useState(null);
  const [page, setPage] = useState('home');
  const [playlists, setPlaylists] = useState([
    { id:'pl0', name:'Liked Songs', emoji:'💚', tracks: [] },
  ]);
  const [currentPlaylist, setCurrentPlaylist] = useState(null);
  const [currentTrack, setCurrentTrack] = useState(null);
  const [isPlaying, setIsPlaying] = useState(false);
  const [progress, setProgress] = useState(0);
  const [shuffle, setShuffle] = useState(false);
  const [repeat, setRepeat] = useState(false);
  const [volume, setVolume] = useState(0.8);
  const [liked, setLiked] = useState(false);
  const [showCreateModal, setShowCreateModal] = useState(false);
  const [showAddModal, setShowAddModal] = useState(null); // track to add
  const [toast, setToast] = useState(null);
  const progressRef = useRef(null);

  // Check for Spotify token in URL hash
  useEffect(() => {
    const t = getTokenFromHash();
    if (t) {
      window.history.replaceState({}, '', window.location.pathname);
      setToken(t);
      spotifyFetch('/me', t).then(me => {
        if (me) setUser({ name: me.display_name || me.id, email: me.email });
        else setUser({ name: 'Spotify User', email: '' });
      });
    }
  }, []);

  // Progress ticker
  useEffect(() => {
    if (isPlaying) {
      progressRef.current = setInterval(() => setProgress(p => p >= 240 ? 0 : p + 1), 1000);
    } else {
      clearInterval(progressRef.current);
    }
    return () => clearInterval(progressRef.current);
  }, [isPlaying]);

  const showToast = (msg) => setToast(msg);

  const playTrack = (track) => {
    setCurrentTrack(track);
    setIsPlaying(true);
    setProgress(0);
  };

  const togglePlay = () => setIsPlaying(p => !p);

  const skipNext = () => {
    // Pick from demo pool
    const all = Object.values(DEMO_TRACKS).flat();
    const idx = all.findIndex(t => t.id === currentTrack?.id);
    const next = all[(idx + 1) % all.length];
    playTrack(next);
  };

  const skipPrev = () => {
    if (progress > 3) { setProgress(0); return; }
    const all = Object.values(DEMO_TRACKS).flat();
    const idx = all.findIndex(t => t.id === currentTrack?.id);
    playTrack(all[(idx - 1 + all.length) % all.length]);
  };

  const createPlaylist = (name, desc, emoji) => {
    const pl = { id: 'pl' + Date.now(), name, desc, emoji, tracks: [] };
    setPlaylists(prev => [...prev, pl]);
    setShowCreateModal(false);
    setCurrentPlaylist(pl);
    setPage('playlist');
    showToast(`✅ Playlist "${name}" created!`);
  };

  const addToPlaylist = (playlistId) => {
    const track = showAddModal;
    setPlaylists(prev => prev.map(pl =>
      pl.id === playlistId
        ? { ...pl, tracks: pl.tracks.some(t=>t.id===track.id) ? pl.tracks : [...pl.tracks, track] }
        : pl
    ));
    setShowAddModal(null);
    showToast(`🎵 Added to playlist!`);
  };

  if (!user) {
    return <LoginPage onDemoLogin={(u) => { setUser(u); setToken('demo'); }} />;
  }

  const initials = user.name.split(' ').map(n=>n[0]).join('').toUpperCase().slice(0,2);

  return (
    <div className="app-layout">
      <Sidebar
        page={page} setPage={setPage}
        playlists={playlists}
        onCreatePlaylist={() => setShowCreateModal(true)}
        currentPlaylist={currentPlaylist}
        setCurrentPlaylist={setCurrentPlaylist}
      />

      <main className="main-content">
        <div className="main-header">
          <div className="header-nav">
            <button className="header-nav-btn">◀</button>
            <button className="header-nav-btn">▶</button>
          </div>
          <div className="header-user" onClick={() => showToast('👋 Profile coming soon!')}>
            <div className="avatar">{initials}</div>
            <span>{user.name}</span>
          </div>
        </div>

        {page === 'home' && <HomePage onPlay={playTrack} currentTrack={currentTrack} playlists={playlists} onAddToPlaylist={t=>setShowAddModal(t)} token={token} />}
        {page === 'search' && <SearchPage onPlay={playTrack} currentTrack={currentTrack} token={token} />}
        {page === 'moods' && <MoodsPage onPlay={playTrack} currentTrack={currentTrack} token={token} onAddToPlaylist={t=>setShowAddModal(t)} />}
        {page === 'library' && <LibraryPage playlists={playlists} setPage={setPage} setCurrentPlaylist={setCurrentPlaylist} onCreatePlaylist={() => setShowCreateModal(true)} />}
        {page === 'playlist' && currentPlaylist && (
          <PlaylistView playlist={playlists.find(p=>p.id===currentPlaylist.id)||currentPlaylist} onPlay={playTrack} currentTrack={currentTrack} />
        )}
      </main>

      <NowPlayingBar
        track={currentTrack}
        isPlaying={isPlaying}
        togglePlay={togglePlay}
        skipNext={skipNext}
        skipPrev={skipPrev}
        shuffle={shuffle} repeat={repeat}
        toggleShuffle={() => setShuffle(s=>!s)}
        toggleRepeat={() => setRepeat(r=>!r)}
        liked={liked} toggleLike={() => { setLiked(l=>!l); showToast(liked?'Removed from Liked Songs':'💚 Added to Liked Songs'); }}
        progress={progress} volume={volume} setVolume={setVolume}
        onAddToPlaylist={t => setShowAddModal(t)}
      />

      {showCreateModal && <CreatePlaylistModal onCreate={createPlaylist} onClose={() => setShowCreateModal(false)} />}
      {showAddModal && <AddToPlaylistModal playlists={playlists} track={showAddModal} onAdd={addToPlaylist} onClose={() => setShowAddModal(null)} />}
      {toast && <Toast msg={toast} onDone={() => setToast(null)} />}
    </div>
  );
}

ReactDOM.createRoot(document.getElementById('root')).render(<App />);
</script>
</body>
</html>