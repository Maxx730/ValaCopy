    # project name and programming language
    project('kCopy', 'vala', 'c')
     sql = dependency('sqlite3',required: false)

     install_data('src/com.github.Maxx730.kcopy.gschema.xml',
     install_dir : 'share/glib-2.0/schemas')

    # Create a new executable, list the files we want to compile, list the dependencies we need, and install
    executable(
        meson.project_name(),
        'src/Main.vala',
        'src/Application.vala',
        'src/Window.vala',
        'src/HeaderBar.vala',
        'src/ClipboardList.vala',
        'src/Clipboard.vala',
        'src/Settings.vala',
        'src/Data.vala',
        'src/Menu.vala',
        'src/Clip.vala',
        dependencies: [
            dependency('gtk+-3.0'),
            dependency('glib-2.0'),
            sql
        ],
        install: true
    )