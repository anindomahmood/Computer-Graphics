<div align="center">
    <h1>Waves of Cox's Bazar: A Coastal Visualization</h1>
    <p><strong>A 2D Interactive Computer Graphics Simulation using OpenGL & GLUT</strong></p>
</div>

<hr />

<h3>Academic Context</h3>
<ul>
    <li><strong>Institution:</strong> American International University-Bangladesh (AIUB)</li>
    <li><strong>Semester:</strong> Spring 2025-26</li>
    <li><strong>Course Title:</strong> Computer Graphics (CSC4118, Section D)</li>
    <li><strong>Course Teacher:</strong> Mahfujur Rahman</li>
</ul>

<hr />

<h3>Group Members</h3>
<table border="1" cellpadding="8" cellspacing="0" width="100%">
    <thead>
        <tr bgcolor="#f2f2f2">
            <th align="left">Name</th>
            <th align="left">Student ID</th>
            <th align="left">Program</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>Anindo Mahmood</td>
            <td>23-55004-3</td>
            <td>B.Sc. in Computer Science & Engineering (CSE)</td>
        </tr>
        <tr>
            <td>Rifat Hasan</td>
            <td>23-55022-3</td>
            <td>B.Sc. in Computer Science & Engineering (CSE)</td>
        </tr>
        <tr>
            <td>Nishat Tasnim Ema</td>
            <td>23-55025-3</td>
            <td>B.Sc. in Computer Science & Engineering (CSE)</td>
        </tr>
    </tbody>
</table>

<hr />

<h3>1. Project Overview</h3>
<p>
    <strong>Waves of Cox's Bazar</strong> is an immersive 2D visual application designed to capture the iconic environments, changing atmospheric states, and local lifestyle landmarks of the world's longest natural sea beach. Built inside a custom 2D orthographic projection grid mapping coordinate spaces from <code>(-800, 800)</code> on the X-axis to <code>(-600, 600)</code> on the Y-axis, the project implements complex state transitions, geometric rendering matrices, smooth double-buffer animations, and synchronized audio behaviors.
</p>

<hr />

<h3>2. Screen Layouts & Features</h3>

<h4>Title / Cover Page Sequence</h4>
<ul>
    <li>Renders a structured introductory interface featuring AIUB institutional identity tags.</li>
    <li>Displays structured student records alongside core supervisor definitions aligned inside explicit graphic borders.</li>
</ul>

<h4>Interactive Keyboard Setup Board</h4>
<ul>
    <li>Functions as a runtime documentation screen explaining hotkeys, acceleration hooks, and layout state configurations.</li>
</ul>

<h4>Marine Drive System (Scene E , Designed by: Nishat Tasnim Ema)</h4>
<ul>
    <li><strong>Scenery Elements:</strong> Features an asphalt shoreline highway flanked by mountain ridge profiles, dynamic vegetation, and rolling sea currents.</li>
    <li><strong>Day & Night Cycle:</strong> Driven by continuous solar vector calculations. When the sun dips beneath the horizon plane, the frame transitions from bright blue sky gradients into a deep starfield system.</li>
    <li><strong>Animations:</strong> Dual cloud decks traveling at individual velocities, a moving road vehicle, and an offshore container ship crossing the bay.</li>
    <li><strong>Dynamic Audio:</strong> Cycles seamlessly based on environmental changes, alternating between active day waves, car horns, ship alerts, and crickets at night.</li>
</ul>

<h4>Traditional Fishing Village (Scene F , Designed by: Anindo Mahmood)</h4>
<ul>
    <li><strong>Scenery Elements:</strong> Illustrates coastal settlements with textured thatch-roof huts, localized palm tree lines, and matching sand-to-water shoreline slopes.</li>
    <li><strong>Animations:</strong> Synchronized cloud drifting, solar vectors, and local wooden rowboats moving with the water currents.</li>
    <li><strong>Audio System:</strong> Pairs paddle boat wave splashing audios with the daytime look, switching over to night ambient cues at dusk.</li>
</ul>

<h4>Busy Beach Shoreline (Scene R , Designed by: Rifat Hasan)</h4>
<ul>
    <li><strong>Scenery Elements:</strong> Recreates the sandy tourist shores of Cox's Bazar with detailed relaxation beach chairs, striped sun umbrellas, and ambient coastal breaks.</li>
    <li><strong>Sky Atmosphere:</strong> Utilizes warm color palettes (terracotta, orange, and gold) combined in blending passes to simulate true sunset horizons.</li>
    <li><strong>Animations:</strong> Multi-tiered cloud arrays (four individual moving systems) passing overhead while a large cruise ship sails on the horizon line.</li>
</ul>

<hr />

<h3>3. Controls & Interactivity</h3>
<table border="1" cellpadding="8" cellspacing="0" width="100%">
    <thead>
        <tr bgcolor="#f2f2f2">
            <th align="left">Input Trigger</th>
            <th align="left">Target Action</th>
            <th align="left">System Operational Response</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><code>Mouse Right Click</code></td>
            <td>Menu Navigation Click</td>
            <td>Cycles sequentially through active display states: Cover Page &rarr; Instructions &rarr; Marine Drive &rarr; Fishing Village &rarr; Busy Shoreline.</td>
        </tr>
        <tr>
            <td><code>Keyboard 'W' / 'w'</code></td>
            <td>Key Hold / Tap Input</td>
            <td>Systematically increases rendering translation velocities across clouds, sea craft, and moving road vehicles.</td>
        </tr>
        <tr>
            <td><code>Keyboard 'S' / 's'</code></td>
            <td>Key Hold / Tap Input</td>
            <td>Decrements movement offsets until reaching a lower bounds value of <code>0</code>, completely pausing scene animations.</td>
        </tr>
    </tbody>
</table>

<hr />

<h3>4. Technical Details & System Architecture</h3>
<ul>
    <li><strong>Language standard:</strong> C++ (using <code>math.h</code> for parametric calculations of circular geometry and <code>cstring</code> for text bitmapping).</li>
    <li><strong>Graphics Stack:</strong> OpenGL via freeglut framework using double/single buffer configuration matrices.</li>
    <li><strong>Audio Processing API:</strong> Win32 Multi-threaded Asynchronous Audio Engine (<code>PlaySound()</code> targeting <code>SND_ASYNC | SND_FILENAME</code> loops).</li>
</ul>

<h4>Required Workspace Audio Footprint</h4>
<p>Make sure the following <code>.wav</code> sound assets are located directly within your executable binary root folder directory to keep audio features functional:</p>
<ul>
    <li><code>freesound_community-car-horn-6408.wav</code></li>
    <li><code>mixkit-small-waves-harbor-rocks-1208 (1).wav</code></li>
    <li><code>freesound_community-ship-horn-6456.wav</code></li>
    <li><code>schorsch1964-night-atmosphere-with-crickets-374652.wav</code></li>
    <li><code>freesound_community-paddle-boat-on-waterwav-14861.wav</code></li>
    <li><code>kokoreli777-sea-waves-169411.wav</code></li>
</ul>
