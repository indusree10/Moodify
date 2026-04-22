# 🎵 Moodify — Emotion-Based Music Recommender

<div align="center">

![Moodify Banner](https://img.shields.io/badge/Moodify-Emotion--Based%20Music-1DB954?style=for-the-badge&logo=spotify&logoColor=white)

**A Spotify-inspired web app that recommends music based on your mood.**  
Built with React · HTML · CSS · Spotify Web API

[![Live Demo](https://img.shields.io/badge/Live-Demo-1DB954?style=flat-square&logo=vercel&logoColor=white)](#)
[![MIT License](https://img.shields.io/badge/License-MIT-blue?style=flat-square)](#license)
[![Made with React](https://img.shields.io/badge/Made%20with-React%2018-61DAFB?style=flat-square&logo=react&logoColor=black)](https://reactjs.org)
[![Spotify API](https://img.shields.io/badge/Spotify-Web%20API-1DB954?style=flat-square&logo=spotify&logoColor=white)](https://developer.spotify.com)

</div>

---

## 📸 Screenshots

| Login Page | Mood Selection | Playlist View |
|---|---|---|
| 🔐 Glassmorphism login with Spotify OAuth | 🎭 6 mood cards with curated tracks | 📋 Full playlist management |

---

## ✨ Features

- 🔐 **Authentication** — Email/password login + Spotify OAuth (implicit grant flow)
- 🎭 **6 Mood Categories** — Happy, Sad, Chill, Party, Romantic, Angry
- 🎵 **Smart Recommendations** — Real Spotify search results per mood (demo fallback included)
- 📋 **Playlist Management** — Create, name, emoji-tag, and fill playlists
- ➕ **Add to Playlist** — Add any recommended song to any of your playlists
- 🔍 **Search** — Real-time search with genre browsing
- ▶️ **Now Playing Bar** — Play/pause, skip, shuffle, repeat, volume, progress
- 💚 **Like Songs** — Heart tracks and add them to Liked Songs
- 📱 **Spotify-Replica UI** — Sidebar, cards, player bar — all pixel-close to Spotify's design
- 🌗 **Demo Mode** — Works fully offline without a Spotify API key

---

## 🚀 Getting Started

### Option 1 — Open directly in browser (no setup)

```bash
# Clone the repo
git clone https://github.com/your-username/moodify.git
cd moodify

# Open in browser
open moodify.html
# or just double-click moodify.html
```

> The app runs in **Demo Mode** with pre-loaded tracks. No API key required.

---

### Option 2 — Connect to Spotify (full experience)

#### Step 1 — Create a Spotify App

1. Go to [developer.spotify.com/dashboard](https://developer.spotify.com/dashboard)
2. Click **Create App**
3. Fill in:
   - **App Name:** Moodify
   - **App Description:** Emotion-based music recommender
   - **Redirect URI:** `http://localhost:3000` *(or your deployment URL)*
   - **APIs Used:** Web API
4. Click **Save** and copy your **Client ID**

#### Step 2 — Add your Client ID

Open `moodify.html` and replace line near the top:

```js
const CLIENT_ID = 'YOUR_SPOTIFY_CLIENT_ID'; // ← Replace this
const REDIRECT_URI = 'http://localhost:3000'; // ← Match your Redirect URI
```

#### Step 3 — Serve locally (required for OAuth)

```bash
# Using Python
python3 -m http.server 3000

# Using Node.js / npx
npx serve . -p 3000

# Using VS Code
# Install "Live Server" extension → right-click moodify.html → Open with Live Server
```

Then visit `http://localhost:3000/moodify.html` and click **Continue with Spotify**.

---

## 🎭 Mood Categories

| Mood | Vibe | Search Query Used |
|------|------|-------------------|
| 😄 Happy | Upbeat & joyful | `happy upbeat pop` |
| 😢 Sad | Melancholic feels | `sad emotional heartbreak` |
| 😎 Chill | Relaxed & laid back | `chill lofi relaxed ambient` |
| 🎉 Party | High energy bangers | `party dance edm club` |
| 💕 Romantic | Love & romance | `romantic love ballad` |
| 😤 Angry | Raw & intense energy | `rock metal intense angry` |

---

## 🗂️ Project Structure

```
moodify/
│
├── moodify.html          # Single-file app (React + CSS + JS bundled)
├── README.md             # You're reading this
└── LICENSE               # MIT License
```

> Moodify is intentionally a **single HTML file** — zero build tools, zero dependencies to install. Just open and run.

---

## 🛠️ Tech Stack

| Technology | Usage |
|---|---|
| **React 18** | UI components & state management (via CDN) |
| **Babel Standalone** | JSX transpilation in-browser |
| **Vanilla CSS** | Full custom Spotify-replica styles |
| **Spotify Web API** | Track search, user auth, playlists |
| **Spotify OAuth 2.0** | Implicit Grant Flow for browser auth |

---

## 🔑 Spotify API Scopes Used

```
streaming
user-read-email
user-read-private
user-library-modify
playlist-modify-public
playlist-modify-private
user-read-playback-state
user-modify-playback-state
```

---

## 🧩 Key Components

| Component | Description |
|---|---|
| `LoginPage` | Glassmorphism login with Spotify OAuth + email/password |
| `Sidebar` | Spotify-style navigation with playlist list |
| `MoodsPage` | Mood card grid + dynamic track recommendations |
| `SearchPage` | Real-time search with genre category browsing |
| `LibraryPage` | User's playlist collection |
| `PlaylistView` | Full playlist with track rows and playback |
| `NowPlayingBar` | Persistent bottom player with controls |
| `CreatePlaylistModal` | Playlist creation with emoji picker |
| `AddToPlaylistModal` | Add track to any existing playlist |

---

## ⚙️ Configuration

All configurable constants are at the top of `moodify.html`:

```js
const CLIENT_ID    = 'YOUR_SPOTIFY_CLIENT_ID';  // Spotify app client ID
const REDIRECT_URI = window.location.href;       // Auto-detected or set manually
const SCOPES       = 'streaming user-read-email ...'; // Spotify permission scopes
```

---

## 🌐 Deployment

### Deploy to GitHub Pages

```bash
# 1. Push to GitHub
git add .
git commit -m "Initial commit"
git push origin main

# 2. Go to repo Settings → Pages
# 3. Source: Deploy from branch → main → / (root)
# 4. Your app will be live at: https://your-username.github.io/moodify/moodify.html
```

> ⚠️ Remember to add your GitHub Pages URL as a **Redirect URI** in your Spotify Developer Dashboard.

### Deploy to Netlify / Vercel

Simply drag and drop the `moodify.html` file into Netlify's deploy area, or connect the repo. No build step needed.

---

## 🐛 Troubleshooting

| Problem | Fix |
|---|---|
| **"Continue with Spotify" opens alert** | Replace `CLIENT_ID` with your real Spotify Client ID |
| **Redirect URI mismatch error** | Ensure the URI in your Spotify Dashboard exactly matches your current URL |
| **No tracks load for moods** | Check your Client ID and that the token hasn't expired (tokens last 1 hour) |
| **OAuth doesn't work on `file://`** | Serve via a local server (see Step 3 above) — browsers block OAuth on file:// |
| **CORS errors in console** | This is expected for the Spotify SDK on localhost; use `http://localhost` not `file://` |

---

## 🗺️ Roadmap

- [ ] Spotify Playback SDK integration (actual audio playback)
- [ ] Persist playlists to Spotify account via API
- [ ] Mood detection via webcam (facial expression AI)
- [ ] Lyrics display panel
- [ ] Mobile responsive layout
- [ ] Dark / Light theme toggle
- [ ] Recently played history
- [ ] Share playlist via link

---

## 🤝 Contributing

Contributions are welcome! Here's how:

```bash
# 1. Fork the repo
# 2. Create a feature branch
git checkout -b feature/your-feature-name

# 3. Make your changes to moodify.html
# 4. Commit with a clear message
git commit -m "feat: add lyrics panel"

# 5. Push and open a Pull Request
git push origin feature/your-feature-name
```

---

## 📄 License

```
MIT License

Copyright (c) 2024 Your Name

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
```

---

## 🙏 Acknowledgements

- [Spotify Web API](https://developer.spotify.com/documentation/web-api) — for the music data
- [React](https://reactjs.org) — for the UI framework
- [Spotify Design](https://spotify.design) — for UI/UX inspiration

---

<div align="center">

Made with 💚 and good vibes &nbsp;|&nbsp; Give it a ⭐ if you like it!

</div>
